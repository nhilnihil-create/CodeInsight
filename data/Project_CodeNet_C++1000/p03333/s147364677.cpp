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

int n, l[maxn], r[maxn];
long long ans;

int main()
{
	#ifdef MPS
		fp("1.in","r",stdin);
		fp("1.out","w",stdout);
	#endif
	sf("%d",&n);
	fo(i,1,n) sf("%d%d",&l[i],&r[i]);
	sort(l,l+n+1); reverse(l,l+n+1);
	sort(r,r+n+1);
	fo(i,0,n) if(l[i]-r[i]>0) ans += 2*(l[i]-r[i]);
	pf("%lld\n",ans);
	return 0;
}