#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    int cnt0 = 0;
    int cnt1 = 0;
    if (s.length() == 1)
    {
        cnt = 0;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                cnt0++;
            }
            if (s[i] == '1')
            {
                cnt1++;
            }
        }
        cnt = min(cnt1, cnt0) * 2;
    }
    // while (i < s.length())
    // {
    //     if (s[i] == '0' && s[i + 1] == '1')
    //     {
    //         s.erase(s.begin() + i, s.begin() + i + 2);
    //         i = 0;
    //         cnt += 2;
    //     }
    //     else
    //     {
    //         i++;
    //     }
    //     // cout << i << endl;
    // }
    cout << cnt << endl;
    return 0;
}
