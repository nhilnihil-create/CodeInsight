#include<bits/stdc++.h>
#define ll long long 
using namespace std;
double dp[3001][3001];
double solve(double p[],int i,int x){
    if(x==0)
        return 1;
    if(i==0)
        return 0;
    if(dp[i][x] > -0.9)
        return dp[i][x];
    return dp[i][x]=p[i]*solve(p,i-1,x-1) +(1-p[i])*solve(p,i-1,x);
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    double p[n+1];
    for(int i=1;i<=n;i++)
        cin>>p[i];
    
    cout<<fixed<<setprecision(10)<<solve(p,n,n/2+1)<<endl;
    return 0;
}