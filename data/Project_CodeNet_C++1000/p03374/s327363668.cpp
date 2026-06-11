#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
ll vsum[114514],rvl[114514],lvl[114514];
int main(){
	ll n,c;
	cin>>n>>c;
	vector<ll> x,v;
	x.pb(0);
	v.pb(0);
	for(int i=0;i<n;i++){
		ll tmpx,tmpv;
		cin>>tmpx>>tmpv;
		x.pb(tmpx);
		v.pb(tmpv);
	}
	x.pb(c);
	v.pb(0);
	vsum[1] = v[1];
	for(int i=1;i<n;i++){
		vsum[i+1] = vsum[i] + v[i+1];
	}
	for(int i=1;i<=n;i++){
		lvl[i] = vsum[i]-x[i];
		rvl[i] = (vsum[n] - vsum[i-1]) - (c-x[i]);
	}
	for(int i=1;i<=n;i++){
		if(lvl[i]<lvl[i-1])lvl[i]=lvl[i-1];
	}
	for(int i=n;i>=1;i--){
		if(rvl[i]<rvl[i+1])rvl[i]=rvl[i+1];
	}
	ll ans = 0;
	// 0 -> L -> 0 -> R
	for(int i=0;i<=n;i++){
		ll tmp = vsum[i] - 2*x[i];
		tmp += rvl[i+1];
		if(tmp>ans)ans = tmp;
	}
	for(int i=n+1;i>=1;i--){
		ll tmp = (vsum[n] - vsum[i-1]) - 2*(c-x[i]);
		tmp += lvl[i-1];
		if(tmp>ans)ans=tmp;
	}
	cout<<ans<<endl;
	return 0;
}