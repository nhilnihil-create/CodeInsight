#include<bits/stdc++.h>
#define ll long long int
#define db long double
#define ull unsigned long long int
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
#define INF 1000000000
#define MOD 1000000007
#define MAXN 1000005
 
using namespace std;

ll dp[200005];
ll seg[800005];

void update(ll node,ll tl,ll tr,ll pos,ll val)
{
	if(pos>tr || pos<tl) return ;
	if(pos==tl && pos==tr)
	{
		seg[node]=val;
		return ;
	}
	ll tm=(tl+tr)/2;
	if(pos<=tm) update(2*node,tl,tm,pos,val);
	else update(2*node+1,tm+1,tr,pos,val);
	seg[node]=max(seg[2*node],seg[2*node+1]);
}

ll query(ll node,ll tl,ll tr,ll l,ll r)
{
	if(l>tr || tl>r) return 0;
	if(l<=tl && r>=tr)
	{
		return seg[node];
	}
	ll tm=(tl+tr)/2;
	ll left=query(2*node,tl,tm,l,r);
	ll right=query(2*node+1,tm+1,tr,l,r);
	return max(left,right);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int tests=1;
    // compute();
    // cin>>tests;
    while(tests--)
    {
    	ll i,j,k,n;
    	cin>>n;
    	vector<ll>h(n+1),a(n+1),ind(n+1,0);
    	rep(i,1,n) cin>>h[i];
    	rep(i,1,n) cin>>a[i];

    	dp[1]=a[1];
    	update(1,1,n,h[1],a[1]);
    	rep(i,2,n)
    	{
    		ll val=query(1,1,n,1,h[i]);
    		dp[i]=val+a[i];
    		update(1,1,n,h[i],dp[i]);
    	}
    	ll ans=0;
    	rep(i,1,n) ans=max(ans,dp[i]);
    	cout<<ans;

    }
    	return 0;
    
}