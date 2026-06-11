#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    rep(i, n) cin >> v[i], v[i] = abs(v[i] - x);
    int ans = v[n - 1];
    rep(i, n - 1) ans = __gcd(ans, v[i]);
    cout << ans << endl;
}