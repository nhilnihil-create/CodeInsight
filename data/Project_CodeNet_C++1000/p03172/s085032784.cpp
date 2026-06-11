#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
ll mod=1000000007;

ll fun(int n,int k,int *a){
    ll dp[n+1][k+1];
    for(int i=0; i<=k; i++){
        dp[1][i]= i>a[0]?0:1;
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(j==0){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=mod+dp[i-1][j]+dp[i][j-1]-((j-a[i-1]-1) >= 0?dp[i-1][j-a[i-1]-1]:0);
                dp[i][j]%=mod;
            }
        }
    }
    return dp[n][k];
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<fun(n,k,a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--){
        solve();
        cout<<endl;
    }
}
