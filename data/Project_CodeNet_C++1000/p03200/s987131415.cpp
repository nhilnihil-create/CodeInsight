#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;
    int64_t ans = 0;
    int64_t b_cnt = 0;
    rep(i, s.size())
    {
        if (s[i] == 'W')
        {
            ans += b_cnt;
        }
        else
        {
            b_cnt++;
        }
    }
    cout << ans << endl;
}