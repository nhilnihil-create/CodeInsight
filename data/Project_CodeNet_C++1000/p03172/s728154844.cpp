#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>

#define MEM(var,val) memset(var,(val),sizeof(var))
const int M=1e9+7;
vll a;
ll n,k;
vector<vll>dp;
vll pref;
void dist(ll i)
{
    for(int j=0;j<=k;j++)
    if(j>a[i])
        dp[i][j]=(pref[j]-pref[j-a[i]-1]+M)%M;
    else 
        dp[i][j]=pref[j];
    pref[0]=dp[i][0];
    for(int j=1;j<=k;j++)
        pref[j]=(pref[j-1]+dp[i][j])%M;
    if(i>0)
        dist(i-1);
    return ;
}
int main()
{
  
    cin>>n>>k;
    dp.resize(n+1,vll(k+1,0));
    a.resize(n+1);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int j=0;j<=a[n-1];j++)
    dp[n-1][j]=1;
    pref.resize(k+1,0);
    pref[0]=1;
    for(int j=1;j<=k;j++)
    pref[j]=pref[j-1]+dp[n-1][j];
    //MEM(dp,-1);
    if(n>=2)
    dist(n-2);
    cout<<dp[0][k]%M;

}