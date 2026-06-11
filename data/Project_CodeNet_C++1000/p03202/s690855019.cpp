// FUCKED UP FUCKED UP FUCKED UP FUCKED UP FUCKED UP
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MP make_pair

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e5+10, maxm=5e4+10, lg=21, mod=1e9+7, inf=1e18;

ll n,a[maxn];
bool check(ll d){
	map<ll,ll> mp;
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]) continue;
		if(d==1) return 0;
		ll r=a[i];
		while(mp[r]==d-1) mp[r--]=0;
		if(r==0) return 0;
		mp[r]++;
		mp.erase(mp.upper_bound(r),mp.end());
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	ll l=0,r=n,mid;
	while(r-l>1){
		mid=(l+r)/2;
		(check(mid) ? r:l)=mid;
	}
	cout<<r;
	
	return 0;
}




