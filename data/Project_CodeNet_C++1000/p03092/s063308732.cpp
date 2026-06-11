#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    int p[n];
    rep(i,n){
        cin >> p[i];
    }
    ll dp[n][n+1];
    ll INF = 1001001001001001001;
    rep(i,n)rep(j,n+1)dp[i][j] = INF;
    rep(i,n){
        if(i == 0){
            dp[i][0] = a;
            dp[i][p[i]] = 0;
        }else{
            int x = p[i];
            dp[i][0] = dp[i-1][0] + a;
            srep(j,1,n+1){
                if(j < x){
                    dp[i][j] = dp[i-1][j] + a;
                }else if(j == x){
                    rep(k,x+1){
                        dp[i][x] = min(dp[i][x], dp[i-1][k]);
                    }
                }else{
                    dp[i][j] = dp[i-1][j] + b;
                }
            }
        }
    }
    ll ans = INF;
    rep(j,n+1)ans = min(ans, dp[n-1][j]);
    cout << ans << endl;
    return 0;
}


