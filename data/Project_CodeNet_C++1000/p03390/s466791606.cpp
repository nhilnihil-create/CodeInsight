#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
#define ITR(v, i) for(auto ite = v.begin(); ite != v.end(); ite++)
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> x >> y;
        a = x * y - 1;
        b = sqrtl(a);
        ans = 2 * (b - 1);
        if(b * (b + 1) <= a)
            ans++;
        if(abs(x - y) < 1)
            ans++;
        cout << ans << endl;
    }
}