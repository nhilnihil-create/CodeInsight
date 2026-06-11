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
    ll n, k;
    cin >> n >> k;
 
    vl x(n), y(n);
    vl vx, vy;
    rep(i, n) {
        cin >> x[i] >> y[i];
        vx.pb(x[i]);
        vy.pb(y[i]);
    }
    sort(all(vx));
    sort(all(vy));
 
    ll ans = (vx[n-1] - vx[0])*(vy[n-1] - vy[0]);
    exrep(i1, 0, n-2) {
        exrep(i2, i1+1, n-1) {
            exrep(j1, 0, n-2) {
                exrep(j2, j1+1, n-1) {
                    ll cnt = 0;
                    rep(k1, n) {
                        if(vx[i1] <= x[k1] && x[k1] <= vx[i2] && vy[j1] <= y[k1] && y[k1] <= vy[j2]) {
                            cnt++;
                        }
                    } 
                    if(cnt >= k) {
                        chmin(ans, (vx[i2] - vx[i1])*(vy[j2] - vy[j1]));
                    }
                }
            }
        }
    }
 
    out(ans);
    re0;
}