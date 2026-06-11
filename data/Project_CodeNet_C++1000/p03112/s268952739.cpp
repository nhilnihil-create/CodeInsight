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
        ll posRji = upper_bound(all(s), x) - s.begin();
        ll posRte = upper_bound(all(t), x) - t.begin();
        ll Rji = s[posRji] - x;
        ll Rte = t[posRte] - x;
        posRji--;  posRte--;
        ll Lji = x - s[posRji];
        ll Lte =  x - t[posRte];
        chmin(ans[i], max(Lji, Lte));
        chmin(ans[i], max(Rji, Rte));
        chmin(ans[i], 2*Lji + Rte);
        chmin(ans[i], 2*Rte + Lji);
        chmin(ans[i], 2*Lte + Rji);
        chmin(ans[i], 2*Rji + Lte);
    }
    
    rep(i, q) {
        out(ans[i]);
    }
    
    re0;
}