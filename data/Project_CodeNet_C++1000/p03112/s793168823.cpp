#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll a, b, q;
    cin >> a >> b >> q;

    vl s(a+2);
    s[0] = -INF;
    exrep(i, 1, a) {
        cin >> s[i];
    }
    s[a+1] = INF;

    vl t(b+2);
    t[0] = -INF;
    exrep(i, 1, b) {
        cin >> t[i];
    }
    t[b+1] = INF;

    vl ans(q, INF);
    rep(i, q) {
        ll x;
        cin >> x;
        ll pos_sR = upper_bound(all(s), x) - s.begin();
        ll pos_tR = upper_bound(all(t), x) - t.begin();
        ll sR = abs(s[pos_sR] - x);
        ll tR = abs(t[pos_tR] - x);
        pos_sR--;  pos_tR--;
        ll sL = abs(s[pos_sR] - x);
        ll tL = abs(t[pos_tR] - x);
        chmin(ans[i], max(sL, tL));
        chmin(ans[i], max(sR, tR));
        chmin(ans[i], 2*sL + tR);
        chmin(ans[i], 2*tL + sR);
        chmin(ans[i], 2*sR + tL);
        chmin(ans[i], 2*tR + sL);
    }

    rep(i, q) {
        out(ans[i]);
    }

    re0;
}