#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    
    vec<int> a(N), b(N), c(N);
    rep(i, N) cin >> a[i] >> b[i] >> c[i];

    vec<vec<ll>> dp(4,vec<ll>(N+1,-1e9));
    dp[0][0] = 0;
    rep(i,N)rep(p,4){
        if(p!=1) dp[1][i+1] = max(dp[1][i+1],dp[p][i]+a[i]);
        if(p!=2) dp[2][i+1] = max(dp[2][i+1],dp[p][i]+b[i]);
        if(p!=3) dp[3][i+1] = max(dp[3][i+1],dp[p][i]+c[i]);
    }
    cout << max({dp[1][N],dp[2][N],dp[3][N]}) << '\n';
}
