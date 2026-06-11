#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;

int main()
{
    string s;
    cin >> s;
    ll ans = 0;
    ll cnt = 0;
    rep(i, s.length() - 1)
    {
        if (s[i] == 'A')
        {
            cnt++;
        }
        else if (s[i] == 'B' && s[i + 1] == 'C')
        {
            ans += cnt;
            i++;
        }
        else
        {
            cnt = 0LL;
        }
    }
    cout << ans << endl;
}