#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,dp[21][1<<21];
bool b[25][25];
const ll mod=1e9+7;
ll best(ll d,ll mask)
{
    if(d==n)return 1;
    if(dp[d][mask]!=-1)
    return dp[d][mask];
    dp[d][mask]++;
    for(ll i=0;i<n;i++)
    if(b[d][i]&&((1<<i)&mask)==0)
    dp[d][mask]=(dp[d][mask]+best(d+1,mask|(1<<i)))%mod;
    return dp[d][mask];
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
for(ll i=0;i<n;i++)
for(ll j=0;j<n;j++)
cin>>b[i][j];
memset(dp,-1,sizeof dp);
cout<<best(0,0);
return 0;
}
