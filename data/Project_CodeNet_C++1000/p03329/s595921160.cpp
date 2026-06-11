#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;
int dp[maxn];
int main()
{
    for(int i=0;i<maxn;i++){
        dp[i]=1e9;
    }
    dp[0]=0;
    for(ll i=0;i<=maxn;i++){
        dp[i+1]=min(dp[i+1],dp[i]+1);
        for(ll j=6;i+j<=maxn;j*=6){
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
        for(ll j=9;i+j<=maxn;j*=9){
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
    }
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
    return 0;
}