#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
int mod=int(1e9)+7;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n+1][3];
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    ll dp[n+1][3];
    memset(dp,0,sizeof(dp));
    dp[1][0]=a[1][0];
    dp[1][1]=a[1][1];
    dp[1][2]=a[1][2];
    for(int i=2;i<=n;i++){
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i][1];
        dp[i][2]=max(dp[i-1][1],dp[i-1][0])+a[i][2];
    }
    cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<"\n";
}