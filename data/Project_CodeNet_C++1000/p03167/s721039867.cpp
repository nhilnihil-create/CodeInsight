#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(i, a) for (auto &i: (a))
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
 
void solve();

 
signed main () {
    clock_t beg = clock();
    cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif 
    int a,b;
    cin>>a>>b;
    int mod = 1000000000 +7;
    int dp[a][b]={};
    int ans[a][b]={};
    char s;
    rep(i,0,a){
        rep(j,0,b){
            cin>>s;
            if(s=='.'){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=0;
            }

        }
    }
    rep(i,0,a){
        rep(j,0,b){
            if(dp[i][j]==0){
                ans[i][j]=0;
            }
            else{
                if(i==0&&j==0){
                    ans[i][j]=1%mod;
                }
                else if(i==0){
                    ans[i][j]=ans[i][j-1]%mod;
                }
                else if(j==0){
                    ans[i][j]=ans[i-1][j]%mod;
                }
                else{
                    ans[i][j]=(ans[i-1][j]%mod+ans[i][j-1]%mod)%mod;
                }
            }
        }
    }

    if(ans[0][0]){
        cout<<ans[a-1][b-1]%mod;
    }
    else{
        cout<<0;
    }
    return 0;
}
