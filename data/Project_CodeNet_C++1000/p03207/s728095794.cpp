#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    ll n;
    cin >> n;
    int ans = 0;
    int mx = 0;
    rep(i, 0, n)
    {
        int tmp;
        cin >> tmp;
        mx = max(mx, tmp);
        ans += tmp;
    }
    cout << ans - mx / 2 << endl;
}
