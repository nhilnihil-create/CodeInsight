#include<bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,m;cin>>n>>m;
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    const int MOD=1e9+7;
    
    int dp[n][m];
    memset(dp,0,sizeof(dp));

    dp[n-1][m-1]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(a[i][j]=='#')    continue;
            if(i+1<n){
                dp[i][j]+=dp[i+1][j];
                dp[i][j]%=MOD;
            }
            if(j+1<m){
                dp[i][j]+=dp[i][j+1];
                dp[i][j]%=MOD;   
            }
        }
    }
    cout<<dp[0][0]<<"\n";
}