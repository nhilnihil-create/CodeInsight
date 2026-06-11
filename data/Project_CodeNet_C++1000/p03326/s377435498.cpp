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
    ll n, m;
    cin >> n >> m;

    vvl v(n, vl(3));
    rep(i, n) {
        rep(j, 3) {
            cin >> v[i][j];
        }
    }

    ll ans = 0;
    rep(b, 1<<3) {
        vl w(n);
        rep(i, n) {
            ll u = 0;
            rep(j, 3) {
                if(b & 1<<j) {
                    u += -v[i][j];
                }
                else {
                    u += v[i][j];
                }
            }
            w[i] = u;
        }
        sort(rall(w));
        ll now = 0;
        rep(i, m) {
            now += w[i];
        }
        chmax(ans, now);
    }
    
    out(ans);
    re0;
}