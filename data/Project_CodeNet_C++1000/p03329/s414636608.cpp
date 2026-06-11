#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll h,w;
ll direction2[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
bool valid(int a,int b)
{
    if(a>=1&&a<=h&&b>=1&&b<=w)return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll dp[100005];
    dp[0]=0;
    for(int i=1;i<=100000;i++)dp[i]=1e7;
    for(int i=0;i<=100000;i++){
        dp[i+1]=min(dp[i+1],dp[i]+1);
        for(int j=6;i+j<=100000;j*=6){
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
        for(int j=9;i+j<=100000;j*=9){
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
    }
    cout<<dp[n];
}
