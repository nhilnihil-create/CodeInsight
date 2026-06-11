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
const ll INF = 1e16;

int main() {
    ll n, Z, W;
    cin >> n >> Z >> W;

    vl a(n+1);
    exrep(i, 1, n) {
        cin >> a[i];
    }

    vvl dp(n, vl(2));  // dp[i][id] : 山札の上からi枚取られている状態でいまの手番がid(id=0:先手, id=1:後手)のときのスコアの最適値
    for(ll i = n-1; i >= 0; i--) {
        // 先手
        dp[i][0] = -INF;
        ll Y = a[i];
        if(i == 0) {
            Y = W;
        }
        chmax(dp[i][0], abs(a[n] - Y));
        exrep(j, i+1, n-1) {
            chmax(dp[i][0], dp[j][1]);
        }
        
        // 後手
        dp[i][1] = INF;
        ll X = a[i];
        if(i == 0) {
            X = Z;
        }
        chmin(dp[i][1], abs(X - a[n]));
        exrep(j, i+1, n-1) {
            chmin(dp[i][1], dp[j][0]);
        }
    }
    
    out(dp[0][0]);
    re0;
}