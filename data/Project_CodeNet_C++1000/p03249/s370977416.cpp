#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
ll n,s[N],a[N],size[N],used[N],d[N];
bool cmp(int x, int y){return a[x]>a[y];}
map<ll,int>Map;Vi b,c;
int main() {
	read(n);rep(i,1,n)read(a[i]),s[i]=i;sort(s+1,s+n+1,cmp);
	rep(i,1,n)size[i]=1,Map[a[i]]=i;
	rep(i,1,n-1){
		int u=s[i];used[u]=1;
		int f=Map[a[u]-(n-2*size[u])];d[f]+=d[u]+size[u];
		if(!f||used[f]){puts("-1");return 0;}
	//	printf("e %d %d\n",u,f);
		b.pb(u);c.pb(f);size[f]+=size[u];
	}
	if(d[s[n]]!=a[s[n]]){puts("-1");return 0;}
	per(i,SZ(b)-1,0)printf("%d %d\n",b[i],c[i]);
//	rep(i,1,n-1)if(a[s[i]])
//	rep(i,1,n-1)printf("%lld %lld\n",s[i],s[i+1]);
	return 0;
}