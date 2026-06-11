#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100100];
ll ans[100100];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll a[n+2];
    dp[1]=0;
    for(ll i=2;i<=n+1;i++)
    {
        cin>>a[i];
        dp[i]=dp[i-1]+a[i];
    }
    ans[1]=0;
    map<ll,ll>m1;
    m1[0]=1;
    for(ll i=2;i<=n+1;i++)
    {
        ll rem=dp[i]%m;
        if(m1.count(rem)==0)
        {
            ans[i]=0;
            m1[rem]=i;
        }
        else
        {
            ans[i]=ans[m1[rem]]+1;
            m1[rem]=i;
        }
    }
    ll sum=0;
    for(ll i=2;i<=n+1;i++)
    {
        sum+=ans[i];
    }
    cout<<sum;
	return 0;
}