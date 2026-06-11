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
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
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
const ll MAX_N = 200010;

int main() {
    ll n;
    cin >> n;
 
    vl c(MAX_N);
    exrep(i, 1, n) {
        cin >> c[i];
    }
 
    vl dp(MAX_N);  // dp[i] : 最初からi個(iは1-index)の石の場合の数
    vl v(MAX_N);  // v[i] : j < i かつ c[j] = c[i] となる最大のj (存在しないときは0)
    vl w(MAX_N);  // vを埋めるための補助的なvector
 
    exrep(i, 1, n) {
        v[i] = w[c[i]];
        w[c[i]] = i;
    }
 
    dp[0] = 1;
    exrep(i, 1, n) {
        dp[i] = dp[i-1];  // i個目の石に操作をしない場合の数はdp[i-1]通り
        if(v[i] != 0 && v[i] != i-1) {  // j < i かつ c[j] = c[i] となるjが存在して、c[i-1] != c[i] のとき
            dp[i] += dp[v[i]];  // i個目とv[i]個目の石に対して操作を行うときの場合の数はdp[v[i]]通り
            dp[i] %= mod;
        }
    }
 
    out(dp[n]);
    re0;
}