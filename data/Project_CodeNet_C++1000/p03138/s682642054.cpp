#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
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
const ll INF = 1e18;
const double pi = acos(-1);

ll dp[2][42];  /* dp[id][i+1] : xの先頭からiビット目まで決めたときのf(x)の最大値。
                                ただし、id = 0 のときxは現時点でkと等しい。
                                id = 1 のときxは現時点でkより小さいことが確定。 */

int main() {
    ll n, k;
    cin >> n >> k;

    vl v0(41);  // v0[i] : 先頭からiビット目の0の個数
    vl v1(41);  // v1[i] : 先頭からiビット目の1の個数
    rep(loop, n) {
        ll a;
        cin >> a;
        exrep(i, 0, 40) {
            ll mask = 1LL<<(40 - i);
            if(mask & a) {
                v1[i]++;
            }
            else {
                v0[i]++;
            }
        }
    }

    rep(id, 2) {
        rep(i, 42) {
            dp[id][i] = -INF;
        }
    }
    
    dp[0][0] = 0;
    exrep(i, 0, 40) {
        ll mask = 1LL<<(40 - i);
        if(k & mask) {  // kの先頭からiビット目が1のとき
            chmax(dp[0][i+1], dp[0][i] + mask*v0[i]);
            chmax(dp[1][i+1], max(dp[1][i] + mask*max(v0[i], v1[i]), dp[0][i] + mask*v1[i]));
        }
        else {  // kの先頭からiビット目が0のとき
            chmax(dp[0][i+1], dp[0][i] + mask*v1[i]);
            chmax(dp[1][i+1], dp[1][i] + mask*max(v0[i], v1[i]));
        }
    }
    
    out(max(dp[0][41], dp[1][41]));
    re0;
}