#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mem(a) memset(a,0,sizeof(a))
typedef long long ll;
typedef pair<ll,ll> pll;
 
const int mn=1e5+5;
 
int n;
ll c;
pll p[mn];
ll pre[mn],suf[mn];
 
priority_queue<ll> qp,qs;
 
int main() {
	scanf("%d%lld",&n,&c);
	for(int i=1; i<=n; i++)
		scanf("%lld%lld",&p[i].first,&p[i].second);
	ll ans=0;
	for(int i=1; i<=n; i++) {
		pre[i]=pre[i-1]+(p[i-1].first-p[i].first)+p[i].second;
		ans=max(ans,pre[i]);
	}
	p[n+1]=make_pair(c,0);
	for(int i=n; i; i--) {
		suf[i]=suf[i+1]+(p[i].first-p[i+1].first)+p[i].second;
		ans=max(suf[i],ans);
	}
	for(int i=1; i<=n; i++) {
		if(!qs.empty()) {
            ans=max(suf[i]+p[i].first-c+qs.top(),ans);
		}
		qs.push(pre[i]);
	}
	for(int i=n; i; i--) {
		if(!qp.empty()) {
            ans=max(pre[i]-p[i].first+qp.top(),ans);
		}
		qp.push(suf[i]);
	}
	cout<<ans;
	return 0;
}