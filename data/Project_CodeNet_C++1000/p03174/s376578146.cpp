#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int a[25][25];
ll dp[30][(1<<21)+1];
ll F(int M ,int W,int n)
{
    if(M==n){
        return 1;
    }
        
    
    if(dp[M][W]!=-1)
        return dp[M][W];
    
    ll ans =0;
   
    for(int i=0;i<n;i++){
        if(W & (1<<i) && a[M][i]==1){
            ans +=(F(M+1,W^(1<<i),n))%MOD;
            ans%=MOD;
        }
    }

    return dp[M][W] = ans;
    

}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
//cout<<((1<<n)-1)<<endl;


    cout<<F(0,(1<<n) -1,n);

    return 0;
}