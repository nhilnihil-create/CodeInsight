#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;
void solve(void)
{
    string s, t;
    cin >> s >> t;
    int len = s.length();
    string ans = "No";
    rep(i, len)
    {
        int cta = 0;
        rep(j, len)
        {
            if (s[j] == t[(j + i) % len])
                cta++;
        }
        if (cta == len)
            ans = "Yes";
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}