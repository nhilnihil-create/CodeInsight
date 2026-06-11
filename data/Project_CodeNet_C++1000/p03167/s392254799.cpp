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
    ll h, w;
    cin >> h >> w;

    vvl dp(h+1, vl(w+1));  // dp[i][j] : (i,j)への経路の数(未確定のとき-1)
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if(s[j] == '.') {
                dp[i+1][j+1] = -1;
            }
        }
    }

    dp[1][1] = 1;
    exrep(i, 1, h) {
        exrep(j, 1, w) {
            if(dp[i][j] == -1) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }

    out(dp[h][w]);
    re0;
}