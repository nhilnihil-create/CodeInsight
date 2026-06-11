#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    ll a[n][n];
    rep(i,n){
        rep(j,n){
            cin >> a[i][j];
        }
    }
    ll g[1 << n] = {};
    for(int bit = 0; bit < (1 << n); bit++){
        rep(i,n){
            for(int j = i + 1; j < n; j++){
                if((bit & (1 << i)) && (bit & (1 << j))) g[bit] += a[i][j];
            }
        }
    }
    vector<ll> dp(1 << n, -INF);
    dp[0] = 0;
    for(int used = 0; used < (1 << n); used++){
        int unused = used ^ ((1 << n) - 1);
        for(int use = unused; use > 0; use = (use - 1) & unused){
            dp[used | use] = max(dp[used | use], dp[used] + g[use]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}