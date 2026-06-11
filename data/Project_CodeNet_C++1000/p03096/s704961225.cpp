#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int, int>;

ll mod = 1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vll c(n), b;
    REP(i, n) cin >> c[i];
    b.push_back(c[0]);
    REP(i, n - 1){
        if(c[i + 1] != c[i]) b.push_back(c[i + 1]);
    }
    n = b.size();
    vll dp(n + 1); // dp[i] : i 文字目までで何通りあるか.
    dp[0] = 1;
    vll latest(2 * 1e5 + 1);
    REP(i, n){
        dp[i + 1] = dp[i];
        if(latest[b[i]]) dp[i + 1] += dp[latest[b[i]]];
        dp[i + 1] %= mod;
        latest[b[i]] = i + 1;
    }
    cout << dp[n] << endl;
    return 0;
}