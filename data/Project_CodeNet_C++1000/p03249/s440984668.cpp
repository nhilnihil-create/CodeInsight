#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=100010;
ll n,dis,d[MAXN],siz[MAXN];
map <ll,int> mp;
pair <int,int> v[MAXN];
int main () {
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&d[i]);
		mp[d[i]]=i,siz[i]=1;
	}
	sort(d+1,d+n+1);
	for (int i=n;i>1;i--) {
		int p=mp[d[i]];
		ll d2=d[i]-(n-siz[p])+siz[p];
		if (mp.find(d2)==mp.end()) {printf("-1\n");return 0;}
		int q=mp[d2];
		siz[q]+=siz[p];
		dis+=siz[p];
		v[n-i+1]=make_pair(p,q);
	}
	if (d[1]!=dis) {printf("-1\n");return 0;}
	for (int i=1;i<n;i++) {
		printf("%d %d\n",v[i].first,v[i].second);
	}
	return 0;
}