#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll nax=2e5+7;

ll n,smt[nax<<4],dp[nax],a[nax],h[nax];

void build(ll node = 1,ll start = 1, ll end = n){
	if (start==end)	smt[node]=dp[start];
	
	else {
		ll mid=(start+end)>>1;
		
		build(node<<1,start,mid);
		build(node<<1|1,mid+1,end);
		
		smt[node]=max(smt[node<<1],smt[node<<1|1]);
	}
}

void update(ll index,ll val,ll node = 1,ll start = 1, ll end = n){
	if (start==end) {
		smt[node] = val;
		dp[index] = val;
	}
	
	else{
		ll mid=(start+end)>>1;
		
		if (index<=mid) update(index,val,node<<1,start,mid);
		
		else  update(index,val,node<<1|1,mid+1,end);
		
		smt[node]=max(smt[node<<1],smt[node<<1|1]);
	}
}

ll query(ll l,ll r,ll node = 1,ll start = 1, ll end = n){
	if (end<l||start>r) return 0;
	
	if (l<=start&&end<=r) return smt[node];
	
	ll mid=(start+end)>>1;
	
	return max(query(l,r,node<<1,start,mid),query(l,r,node<<1|1,mid+1,end));
}

int main(){
//	freopen("input.inp","r",stdin);
//	freopen("output.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	
	for (ll i=0;i<n;++i) cin>>a[i];
	for (ll i=0;i<n;++i) cin>>h[i];
	
	for (ll i=0;i<n;++i){
		dp[a[i]]=query(1,a[i]-1)+h[i];
		update(a[i],dp[a[i]]);
	}
	
	cout<<*max_element(dp+1,dp+n+1)<<"\n";
}