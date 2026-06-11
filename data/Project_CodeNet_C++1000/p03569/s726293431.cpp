#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

bool is_palindrome(const std::string& s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;

    string ss;
    for (auto ch : s)
    {
        if (ch != 'x')
        {
            ss.push_back(ch);
        }
    }
    if (!is_palindrome(ss))
    {
        cout << -1 << endl;
    }
    else
    {
        int x_count = 0;

        int left = 0;
        int right = s.size() - 1;
        for (int i = 0; i < (ss.size() + 1) / 2; i++)
        {
            int left_x = 0;
            while (s[left] != ss[i])
            {
                if (s[left] == 'x')
                {
                    left_x++;
                }
                left++;
            }
            int right_x = 0;
            while (s[right] != ss[i])
            {
                if (s[right] == 'x')
                {
                    right_x++;
                }
                right--;
            }
            x_count += abs(left_x - right_x);

            left++;
            right--;
        }
        cout << x_count << endl;
    }
}
