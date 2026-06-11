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

    vvl d(C, vl(C));  // d[x][y] : マスを色xから色yに塗り替えるときのコスト
    rep(i, C) {
        rep(j, C) {
            cin >> d[i][j];
        }
    }

    vvl c(n, vl(n));  // c[i][j] : マス(i,j)の色
    vvl v(C, vl(3));  // v[x][y] : 色xのマスのうち (i+j)%3 = y となるものの個数
    rep(i, n) {
        rep(j, n) {
            cin >> c[i][j];
            c[i][j]--;
            v[c[i][j]][(i+j)%3]++;
        }
    }
    
    ll ans = INF;
    rep(i, C) {  // (i+j)%3 = 0 のマスを色iで塗る
        rep(j, C) {  // (i+j)%3 = 1 のマスを色jで塗る
            rep(k, C) {  // (i+j)%3 = 2 のマスを色kで塗る
                if(i == j || j == k || k == i) {
                    continue;
                }
                ll now = 0;
                rep(x, C) {
                    now += d[x][i]*v[x][0];
                    now += d[x][j]*v[x][1];
                    now += d[x][k]*v[x][2];
                }
                chmin(ans, now);
            }
        }
    }

    out(ans);
    re0;
}