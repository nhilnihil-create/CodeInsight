#include<bits/stdc++.h>
using namespace std;
//#include<ext/rope>
//using namespace __gnu_cxx
//#include<ext/pb_ds/priority_queue.hpp>
//using namespace __gnu_pbds;
#define lowbit(x) (x&-x)
#define pb push_back
#define empb emplace_back
#define all(x) (x).begin(),(x).end()
#define clr(a,b) memset(a,b,sizeof(a))
#define caze(T) for(cin>>T;T;T--)
#define inf (1<<29)
#define Endl ('\n')
#define fi first
#define se second
#define db double
#define ldb long double
#define ll long long
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
inline char nc() {
	#define SZ 1000000
	static char buf[SZ], *p1, *p2;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
}
template<typename T>
inline int scan(T &x) {
	char c, sign=1; 
	while(!isdigit(c=nc())&&c!=EOF)if(c=='-')sign*=-1;
	if(c==EOF) return EOF;
	for(x = 0; isdigit(c); c = nc())
		x = (x<<1) + (x<<3) + (c&15);
	return x *= sign, 1;
}
template<typename T, typename...Args>
inline int scan(T &x, Args&...args) {
	return scan(x), scan(args...);
}
void no(){exit((cout<<-1<<Endl,0));}
int main()
{IOS;
	int n;cin>>n;
	map<ll,int>id;
	vector<ll>d(n);
	vector<int>x(n);
	vector<vector<int> >G(n);
	vector<int>sz(n,1);
	function<ll(int,int)>dfs=[&](int u,int d)
	{
		ll ret=d;
		for(auto v:G[u])
			ret+=dfs(v,d+1);
		return ret;
	};
	for(int i=0;i<n;++i)
		cin>>d[i],id[d[i]]=i;
	iota(all(x),0);
	sort(all(x),[&](const int&A,const int&B){return d[A]>d[B];});
	for(int i=0;i<n-1;++i)
	{
		int u=x[i];
		ll df=d[u]-n+2*sz[u];
		if(id.find(df)==id.end()) no();
		int fa=id[df];
		G[fa].pb(u);sz[fa]+=sz[u];
	}
	if(d[x[n-1]]!=dfs(x[n-1],0))
		no();
	for(int i=0;i<n;++i)
		for(auto c:G[i])
			cout<<i+1<<' '<<c+1<<Endl;
}