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
    ll n;
    cin >> n;

    vector<double> p(n);
    rep(i, n) {
        cin >> p[i];
    }
    
    vector<vector<double>> dp(n+1, vector<double>(n+2));  // dp[i][j] : i枚目のコインまででj枚表の確率
    dp[0][0] = 1.0;
    rep(i, n) {
        exrep(j, 0, n) {
            dp[i+1][j+1] += p[i]*dp[i][j];
            dp[i+1][j] += (1 - p[i])*dp[i][j];
        }
    }

    double ans = 0.0;
    exrep(j, n/2 + 1, n) {
        ans += dp[n][j];
    }

    exout(ans);
    re0;
}