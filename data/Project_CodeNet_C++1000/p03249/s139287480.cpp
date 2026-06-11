#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define SZ(x) (int((x).size()))
#define se second
#define ll long long
#define pq priority_queue
#define MP make_pair
#define pii pair<int,int>
#define mod 998244353
#define debug(x) cerr<<#x<<"="<<x<<'\n'

const int maxn=1e6+10;

int n;
map <ll,int> mp;
ll D[maxn];
pair<ll,int> d[maxn];
int sz[maxn];
ll f[maxn];
vector <int> e[maxn];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		ll x;
		scanf("%lld",&x);
		d[i]=MP(x,i);
		mp[x]=i;
		D[i]=x;
	}
	sort(d+1,d+n+1);
	reverse(d+1,d+n+1);
	memset(sz,0,sizeof(sz));
	memset(f,0,sizeof(f));
	for (int i=1;i<n;i++) {
		sz[d[i].se]++;
		if (n-2*sz[i]<=0) {
			puts("-1");
			return 0;
		}
		ll want=d[i].fi-(ll)(n-2*sz[d[i].se]);
		if (mp.find(want)==mp.end()) {
			puts("-1");
			return 0;
		}
		e[d[i].se].pb(mp[want]);
		e[mp[want]].pb(d[i].se);
		sz[mp[want]]+=sz[d[i].se];
		f[mp[want]]+=(ll)sz[d[i].se]+f[d[i].se];
	}
	if (f[d[n].se]!=D[d[n].se]) {
		puts("-1");
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=0;j<e[i].size();j++) {
			if (e[i][j]>i) printf("%d %d\n",i,e[i][j]);
		}
	return 0;
}
