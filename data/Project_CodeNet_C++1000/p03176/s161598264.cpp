#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
vector <ll> BIT(4*N+5,0);
void update(ll ptr,ll idx,ll start,ll end,ll val)
{
	if(start==end)
	{
		BIT[ptr] = max(BIT[ptr],val);
		return;
	}
	ll mid = (start + end)/2;
	if(idx>=start && idx<=mid)
		update(2*ptr,idx,start,mid,val);
	else
		update(2*ptr+1,idx,mid+1,end,val);
	BIT[ptr] = max(BIT[ptr*2] , BIT[ptr*2+1]);
	return;
}

ll query(ll ptr,ll start,ll end,ll l,ll r)
{
	if(start>r || l>end || start>end)
		return 0;
	if(start>=l && end<=r)
		return BIT[ptr];
	ll mid = (start + end)/2;
	return max(query(2*ptr,start,mid,l,r),query(2*ptr+1,mid+1,end,l,r));
}	

int main()
{
    IO
	clock_t begin = clock();
    ll n;
    cin>>n;
    ll h[n+1],v[n+1];
    for(ll i=1;i<=n;i++)
    	cin>>h[i];
    for(ll i=1;i<=n;i++)
    	cin>>v[i];
    for(ll i=1;i<=n;i++)
    	update(1,i,1,n,0);
    vector <ll> dp(n+5,0);
    for(ll i=n;i>=1;i--)
    {
    	ll ans = query(1,1,n,h[i],n);
    	// cout<<ans<<endl;
    	dp[i] = v[i] + ans;
    	update(1,h[i],1,n,dp[i]);
    }
    ll ma = 0;
    for(ll i=1;i<=n;i++)
    	ma = max(ma,dp[i]);
    cout<<ma<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}