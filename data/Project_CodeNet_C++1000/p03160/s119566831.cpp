#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
ll dp[200005],a[200005],n;
ll solve(ll idx)
{
    if(idx>=n-1)
        return 0;
    if(dp[idx]!=-1)
        return dp[idx];
    ll res=INT_MAX;
    if(idx+1<n)
        res=min(res,abs(a[idx+1]-a[idx])+solve(idx+1));
    if(idx+2<n)
        res=min(res,abs(a[idx+2]-a[idx])+solve(idx+2));
    return dp[idx]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll i,j,k,x,y,z,m,t,l,r;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<solve(0)<<'\n';
}






