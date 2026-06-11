#include<bits/stdc++.h>
using namespace std;
#define  ll long long int
#define mx 1005
ll b[mx],c[mx];
ll dp[mx][mx];
ll dp1[mx][mx];
ll a[mx][mx];
ll n;

int main()
{
    ll n,m;
    cin>>n>>m;
    char a[n+6][m+6];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='#'){
                dp[i][j]=0;
                continue;
            }
            if(i==1 && j==1) dp[i][j]=1;
            else if(i==1 || j==1){
                if(i==1){
                    dp[i][j]=dp[i][j-1];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];

            dp[i][j]%=1000000007;
        }
    }
    cout<<dp[n][m]<<endl;
}
