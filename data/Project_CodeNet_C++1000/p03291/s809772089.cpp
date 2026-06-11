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
    string s;
    cin >> s;
    ll n = s.size();

    vvl dp(n+1, vl(4));  // dp[i+1][j] : s[i]までで"ABC"のj文字目まで丸をつける方法の数
    dp[0][0] = 1;
    rep(i, n) {
        exrep(j, 0, 3) {
            if(s[i] == '?') {
                dp[i+1][j] += 3*dp[i][j];
                if(j < 3) {
                    dp[i+1][j+1] += dp[i][j];
                }
            }
            else {
                dp[i+1][j] += dp[i][j];
                if(j < 3 && "ABC"[j] == s[i]) {
                    dp[i+1][j+1] += dp[i][j];
                }
            }
            dp[i+1][j] %= mod;
            dp[i+1][j+1] %= mod;
        }
    }

    out(dp[n][3]);
    re0;
}