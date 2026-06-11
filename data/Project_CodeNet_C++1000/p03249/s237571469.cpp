#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const ll INF = 1e9;
inline ll read() {
	ll X = 0,w = 0 ;
	char ch = 0;
	while(!isdigit(ch)) {
		w |= ch == '-';
		ch = getchar();
	}
	while(isdigit(ch)) X = (X<<3) + (X<<1) + (ch ^ 48),ch = getchar();
	return w ? -X : X;
}
ll dat[100005];
pair<ll,ll> p[100005];
ll sz[100005];
ll from[100005];
ll to[100005];
ll n;
int main() {
	cin>>n;
	for(ll i=0; i<n; i++) {
		cin>>dat[i];
		p[i]=make_pair(dat[i],i);
	}
	sort(p,p+n);
	ll id=0;
	ll sum=0;
	for(int i=0; i<n; i++) {
		sz[i]=1;
	}
	for(ll i=n-1; i>=1; i--) {
		ll curid=p[i].second;
		ll tmp=p[i].first;
		ll nx=n-2*sz[curid];
		if(nx<=0) {
			cout<<-1<<endl;
			return 0;
		}
		ll pos=lower_bound(p,p+n,make_pair(tmp-nx,0LL))-p;
		if(p[pos].first!=tmp-nx) {
			cout<<-1<<endl;
			return 0;
		}
		from[id]=p[i].second;
		to[id++]=p[pos].second;
		sum+=sz[curid]*(n-sz[curid])*2;
		sz[p[pos].second]+=sz[curid];
	}
	ll ans=0;
	for(ll i=0; i<n; i++) {
		ans+=dat[i];
	}
	if(sum!=ans) {
		cout<<-1<<endl;
		return 0;
	}
	for(ll i=0; i<id; i++) {
		cout<<from[i]+1<<" "<<to[i]+1<<endl;
	}
	return 0;
}
