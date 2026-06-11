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
    ll n, C;
    cin >> n >> C;

    vvl d(C, vl(C));
    rep(i, C) {
        rep(j, C) {
            cin >> d[i][j];
        }
    }

    vvl e(C, vl(3));  // e[x][y] : 色xで塗られている (i+j)%3 = y となるマスの個数
    rep(i, n) {
        rep(j, n) {
            ll c;
            cin >> c;
            c--;
            e[c][(i+j)%3]++;
        }
    }

    ll ans = INF;
    rep(x, C) {  // (i+j)%3 = 0 となるマスを色xで塗る
        rep(y, C) {  // (i+j)%3 = 1 となるマスを色yで塗る
            rep(z, C) {  // (i+j)%3 = 2 となるマスを色zで塗る
                if(x == y || y == z || z == x) {
                    continue;
                }
                ll now = 0;
                rep(u, C) {
                    now += d[u][x]*e[u][0];
                    now += d[u][y]*e[u][1];
                    now += d[u][z]*e[u][2];
                }
                chmin(ans, now);
            }
        }
    }
    
    out(ans);
    re0;
}