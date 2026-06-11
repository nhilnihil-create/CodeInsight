#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    if (s == "zyxwvutsrqponmlkjihgfedcba")
    {
        cout << -1 << endl;
    }
    else if (s.length() < 26)
    {
        for (int i = 0; i < 26; ++i)
        {
            char c = 'a' + i;
            if (s.find(c) == s.npos)
            {
                s += c;
                break;
            }
        }

        cout << s << endl;
    }
    else
    {
        vector<bool> used(26);

        for (int i = 25; i >= 0; --i)
        {
            int u = s[i] - 'a';

            for (int j = u + 1; j < 26; ++j)
            {
                if (used[j])
                {
                    string ans = "";
                    for (int k = 0; k < i; ++k)
                        ans += s[k];
                    ans += (char)('a' + j);
                    cout << ans << endl;
                    return 0;
                }
            }

            used[u] = true;
        }
    }

    return 0;
}

// abcdefghijklmnopqrstuvwzyx
// abcdefghijklmnopqrstuvx