#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,v) rep(i,0,(int)v.size()-1)
#define mp make_pair
#define fir first
#define sec second
#define pb push_back
#define gc getchar()
#define lint long long
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
#define wrong return !printf("-1\n")
#define N 100010
using namespace std;
typedef pair<int,int> pii;
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
struct P{
	lint d;int id;
	inline bool operator<(const P &p)const{return d>p.d;}
}p[N];int n;
vector<int> g[N];
int us[N],vs[N],sz[N];
lint d[N];map<lint,int> sv;
int getdrt(int x,int l,int rt)
{
	d[rt]+=l;
	Rep(i,g[x]) getdrt(g[x][i],l+1,rt);
	return 0;
}
int getd(int x)
{
	Rep(i,g[x]) d[g[x][i]]=d[x]+n-2*sz[g[x][i]],getd(g[x][i]);
	return 0;
}
int main()
{
	n=inn();
	for(int i=1;i<=n;i++) scanf("%lld",&p[i].d),p[i].id=i,sv[p[i].d]=i;
	for(int i=1;i<=n;i++) sz[i]=1;
	sort(p+1,p+n+1);//from big to small
	for(int i=1;i<n;i++)
	{
		int x=p[i].id;
		lint dlt=n-2*sz[x];
		if(dlt<=0) wrong;
		if(!sv.count(p[i].d-dlt)) wrong;
		int fa=sv[p[i].d-dlt];
		us[i]=fa,vs[i]=x,sz[fa]+=sz[x];
	}
	for(int i=1;i<n;i++) g[us[i]].pb(vs[i]);
	int rt=p[n].id;getdrt(rt,0,rt),getd(rt);
	for(int i=1;i<=n;i++)
		if(d[p[i].id]!=p[i].d) wrong;
	for(int i=1;i<n;i++) printf("%d %d\n",us[i],vs[i]);
}