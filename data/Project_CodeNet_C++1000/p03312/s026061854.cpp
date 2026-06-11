#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int SZ = 200005;
const ll INF = 200000000000005LL;
ll arr[SZ];
ll pre[SZ];
pll mm(int l, int r){
	ll xx = INF,mn,mx;
	int lx = l, rr = r;
	while(lx<=rr){
		int m = (lx+rr)/2;
		ll tmp = pre[r]-pre[m]-(pre[m]-pre[l-1]);
		if(abs(tmp)<xx){
			xx=abs(tmp);
			mn = pre[r]-pre[m];
			mx = pre[m]-pre[l-1];
			if(mx<mn) swap(mn,mx);
		}
		if(tmp>0LL) lx=m+1;
		else rr=m-1;
	}
	return make_pair(mn,mx);
}
int main(void){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+arr[i];
	ll ans = INF;
	for(int i=2;i<=n-2;i++){
		pll x = mm(1,i); pll y = mm(i+1,n);
		ll mn = min(x.first,y.first);
		ll mx = max(x.second,y.second);
		ans = min(mx-mn,ans);
	}
	printf("%lld",ans);
	return 0;
}