#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,dp[100009][2],a[109];
bool best(ll sum,bool b)
{
    ll &r=dp[sum][b];
    if(r!=-1) return r;
    r=b^1;
    for(ll i=0;i<n;i++){
    if(b&&sum>=a[i])
    r|=best(sum-a[i],0);
    if(!b&&sum>=a[i])
    r&=best(sum-a[i],1);
    }
    return r;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>k;
for(ll i=0;i<n;i++)
cin>>a[i];
memset(dp,-1,sizeof dp);
if(best(k,0))
cout<<"Second";
else cout<<"First";
return 0;
}
