#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll dp[101][100001];

ll solve(int i, int j, int A[]){
    if(j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==1 && j>A[i-1]) return 0;
    if(i==1 && j<=A[i-1]) return 1;
    
    ll op=0;
    
    dp[i][j]=(mod+solve(i,j-1,A)+solve(i-1,j,A)-solve(i-1,j-A[i-1]-1,A))%mod;
    return dp[i][j];
 /*   for(ll k=0;k<=A[i-1] && j-k>=0;k++){
        //solve(i-1,j-k,A);
        op+=solve(i-1,j-k,A);
        //dp[i-1][j-k+1]-dp[i-2][j-k+1]+dp[i-2][k-1-A[i-2]];
        op%=mod;
    }
    return dp[i][j]=op;   */
    
}

int main(){
    int n, k; cin>>n>>k;
    int A[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<solve(n,k,A);
 /*   for(int i=0;i<101;i++){
        for(int j=0;j<1001;j++){
            cout<<dp[i][j]<<" ";
        }cout<<"\n";
    }    */
}