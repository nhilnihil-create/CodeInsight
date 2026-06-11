#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a) for (int i = 0; i < (a); i++)
#define repd(i, a) for (int i = (a)-1; i >= 0; i--)
#define reps(i, a, j) for (int i = (j); i < (a); i++)
#define deb(x) cout << #x << " " << x << endl;
#define debs(x) cout << #x << " " << x << " ";
#define deba(x) for (auto _i:x) cout << _i << " ";cout << endl;
#define ms(a) memset(a,0,sizeof(a));
#define mp make_pair
#define eb emplace_back
#define pii pair < int , int >
#define all(a) a.begin(),a.end() 

const int mod = 1e9 + 7;
void solve() {
    int n,k; cin >> n >> k;
    int dp[n][k+1];
    ms(dp);
    rep(i,n) {
        int x; cin >> x;
        rep(j,k+1) {
            if (i == 0) {
                if (j <= x) dp[i][j] = 1;
            }else {
                // for (int no = 0; no <= min(j,x); no++) {
                //     dp[i][j] += (dp[i-1][j-no]);
                // }
                 dp[i][j] = (dp[i-1][j]%mod - (j-min(j,x)-1 >=0 ?dp[i-1][j-min(j,x)-1]:0)%mod + mod)%mod;
            }
        }
        if (i != n-1) reps(j,k+1,1) dp[i][j] = (dp[i][j]%mod + dp[i][j-1]%mod)%mod;
    }
    // rep(i,n) {deba(dp[i]); cout << endl;}
    cout << dp[n-1][k] << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; t=1;
    while (t--) solve();
}



