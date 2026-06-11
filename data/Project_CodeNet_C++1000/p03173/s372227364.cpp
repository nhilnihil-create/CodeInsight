#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[409],dp[409][409];
ll best(ll l,ll r)
{
    if(l==r) return 0;
    ll &ans=dp[l][r];
    if(ans!=-1)return ans;
    ans=LLONG_MAX;
    for(ll i=l;i<r;i++)
    ans=min(ans,best(l,i)+best(i+1,r)+a[r]-a[l-1]);
    return ans;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
memset(dp,-1,sizeof dp);
cin>>n;
for(ll i=1;i<=n;i++){
    cin>>a[i];
    a[i]+=a[i-1];
    dp[i][i]=0;
}
cout<<best(1,n);
return 0;
}
