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
const ll MAX_C = 200010;
 
int main() {
    ll n;
    cin >> n;

    vl c(n);
    rep(i, n) {
        cin >> c[i];
    }

    vl v(n);
    vl w(MAX_C, -1);
    rep(i, n) {
        v[i] = w[c[i]];
        w[c[i]] = i;
    }

    vl dp(n);  // dp[i] : 石iまでの列の個数
    dp[0] = 1;
    exrep(i, 1, n-1) {
        dp[i] += dp[i-1];
        if(v[i] >= 0 && v[i] != i-1) {
            dp[i] += dp[v[i]];
        }
        dp[i] %= mod;
    }

    out(dp[n-1]);
    re0;
}