#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a) for (int i = 0; i < (a); i++)
#define repd(i, a) for (int i = (a)-1; i >= 0; i--)
#define reps(i, a, j) for (int i = (j); i < (a); i++)
#define deb(x) cout << #x << " " << x << endl;
#define debs(x) cout << #x << " " << x << " ";
#define deba(x) for (auto _i:x) cout << _i << " "; cout << endl;
#define ms(a) memset(a,0,sizeof(a));
#define mp make_pair
#define eb emplace_back
#define pii pair < int , int >
#define all(a) a.begin(),a.end()

const int inf = 1e16+7;
int presum(int i, int j, int pre[]) {
    return pre[j] - (i>0?pre[i-1]:0);
}

void solve() {
    int n; cin >> n;
    int arr[n]; rep(i,n) cin >> arr[i];
    int dp[n][n];
    rep(i,n) rep(j,n) dp[i][j] = inf;
    int pre[n]; pre[0] = arr[0]; reps(i,n,1) pre[i] = pre[i-1] + arr[i];
    repd(i,n) {
        rep(j,n) {
            if (i > j) continue;
            if (i == j) dp[i][j] = arr[i];
            else {
                reps(k,j,i) {
                    // dp[i][j] = min(dp[i][j], (k-1>=i?dp[i][k-1]:0) + arr[k] + arr[k+1] + (k+2<=j?dp[k+2][j]:0));
                    dp[i][j] = min(dp[i][j], presum(i,j,pre) + dp[i][k] + dp[k+1][j]); 
                }
            }
        }
    }
    cout << dp[0][n-1] - presum(0,n-1,pre) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; t=1;
    while (t--) solve();
}