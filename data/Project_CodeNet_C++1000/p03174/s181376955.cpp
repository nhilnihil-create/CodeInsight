#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int M=1e9+7;
ll dp[21][1<<21];
int n;
int mat[21][21];
ll calc(int i,int left){
    if(i==n){
        return 1;
    }
    if(dp[i][left]!=-1){
        return dp[i][left];
    }
    ll ans=0;
    for(int j=0;j<n;j++){
        if(mat[i][j]==1){
            int res=1<<j;
            if(left&res){
                ans+=calc(i+1,left^res)%M;  
                ans%=M;
            }
        }
    }
    return dp[i][left]=ans;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    ll sol=calc(0,(1<<21)-1);
    cout<<sol<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
