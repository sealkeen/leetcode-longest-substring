#include <iostream>
#include <string>

using std::string;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t slen = s.length();
        if (slen < 1) return 0;
        if (slen == 1) return 1;

        std::string result = std::string(); // the resulting buffer substring
        int maxLength = 0;                  // this is the cache for result's length
        int fromSubstring = 0;              // this is the position from where to cut the "s"
        char ch = s[0];                     // current character from s
        int plus = 0;                       // plus is the amount of shifting when found similar chars (0/1)
        for (int i = 0; i < slen; i++)
        {
            ch = s[i];
            fromSubstring = result.find(ch);
            if (fromSubstring != std::string::npos) // this is the position where char is found in result
            {
                plus = ((fromSubstring <= 0)    
                    && (result.length() > 1)) 
                    || ((ch == result[0]) // this is the first char is result
                    && (i + 1 < slen)) ? 1 : 0;

                // 1st shift "uun(u)" -> "unu"
                result = result.substr(fromSubstring + plus, result.length()); // shift "ab" -> "b"
                if(plus >= 1 || (ch == result[0]))
                    result += ch;

                // "unu" -> "nu" – 2nd shift if similar chars found
                if (result.length() > 1 && result[0] == ch && result[result.length() - 1] == ch)
                    result = result.substr(1, result.length()); // shift "aba" -> "ba"
            } else {
                result += ch;  // append chars into result
                if(maxLength < result.length())
                    maxLength = result.length();
            }
        }
        return maxLength;
    }
};

int main()
{
    std::cout << Solution().lengthOfLongestSubstring("ab") << std::endl;       //: 2
    std::cout << Solution().lengthOfLongestSubstring("abcb") << std::endl;     //: 3
    std::cout << Solution().lengthOfLongestSubstring("cdd") << std::endl;      //: 2
    std::cout << Solution().lengthOfLongestSubstring("ckilbkd") << std::endl;  //: 5
    std::cout << Solution().lengthOfLongestSubstring("aab") << std::endl;      //: 2
    std::cout << Solution().lengthOfLongestSubstring("dvdf") << std::endl;     //: 3
    std::cout << Solution().lengthOfLongestSubstring("aabaab!bb") << std::endl;//: 3
    std::cout << Solution().lengthOfLongestSubstring("ggububgvfk") << std::endl;//: 6
    system("pause");
    return 0;
}


