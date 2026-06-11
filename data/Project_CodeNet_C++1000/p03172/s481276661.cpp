#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
using ll = long long;
using namespace std;

const ll MOD = 1000000007;

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n); rep(i,n) cin >> a[i];
    
    vector<vector<ll>> ans(n+1,vector<ll>(k+1,0));
    ans[0][0] = 1;
    rep(i,n){
        // 累積和
        vector<ll> sum(k+2,0);
        rep(j,k+1) sum[j+1] = (ans[i][j] + sum[j]) % MOD;
        // DP遷移
        rep(j,k+1) ans[i+1][j] = (sum[j+1] - sum[max(0,j-a[i])] + MOD) % MOD;
    }
    cout << ans[n][k] << endl;
    return 0;
}