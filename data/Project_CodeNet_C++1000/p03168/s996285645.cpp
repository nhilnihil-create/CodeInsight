#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<double>>dp(3000,vector<double>(3000,-1.0));
double func(double a[],ll i, ll x)
{
    if(i<0)
    {
        if(x==0)
        return 1;
     return 0;
    }
    if(x==0)
    return 1;
    if(dp[i][x]!=-1)
    return dp[i][x];
    
    return dp[i][x]=a[i]*func(a,i-1,x-1)+((1-a[i])*(func(a,i-1,x)));
    
}
 
int main() {
   
   ll n,i;
   cin>>n;
   double a[n];
   for(i=0;i<n;i++)
    cin>>a[i];
    // memset(dp,-1,sizeof(dp));
    int x=(n/2)+1;
    cout<< setprecision(16)<<func(a,n-1,x)<<endl;

}