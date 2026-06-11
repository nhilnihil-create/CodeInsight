#include <bits/stdc++.h>
using namespace std;

#define fo(i,s,t) for(int i = s; i <= t; ++ i)
#define fd(i,s,t) for(int i = s; i >= t; -- i)
#define bf(i,s) for(int i = head[s]; i; i = e[i].next)
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define VI vector<int>
#define sf scanf
#define pf printf
#define fp freopen
#define SZ(x) ((int)(x).size())
#ifdef MPS
#define D(x...) printf(x)
#else
#define D(x...)
#endif
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int inf = 1<<30;
const ll INF = 1ll<<60;
const db Inf = 1e20;
const db eps = 1e-9;

void gmax(int &a,int b){a = (a > b ? a : b);}
void gmin(int &a,int b){a = (a < b ? a : b);}

const int maxn = 100050;

int n, sz[maxn];
pair<ll,int> d[maxn];
struct edge{int u, v;}e[maxn];

int main()
{
	// fp("1.in","r",stdin);
	// fp("2.out","w",stdout);
	sf("%d",&n);
	fo(i,1,n) sf("%lld",&d[i].fi), d[i].se = i;
	sort(d+1, d+n+1);
	fd(i,n,2)
	{
		sz[i] ++;
		int l = 1, r = i-1, mid, p = -1;
		while(l <= r)
		{
			mid = (l + r) >> 1;
			if(d[mid].fi <= d[i].fi-n+2*sz[i]) p = mid, l = mid + 1;
			else r = mid - 1;
		}
		if(p == -1 || d[p].fi != d[i].fi-n+2*sz[i]) 
			return 0 * pf("-1\n");
		sz[p] += sz[i];
		e[i].u = d[p].se; e[i].v = d[i].se;
	}
	sz[1] ++;
	ll ans = 0;
	fo(i,1,n) ans += sz[i] * (ll)(n - sz[i]);
	ans <<= 1;
	fo(i,1,n) ans -= d[i].fi;
	if(ans != 0) return 0 * pf("-1\n");
	fo(i,2,n) pf("%d %d\n",e[i].u,e[i].v);
	return 0;
}
