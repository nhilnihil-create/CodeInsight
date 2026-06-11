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
int main()
{IOS;
	int n,mx=0,m=0;cin>>n;
	vector<int>x(n),y(n);
	vector<int>ans;
	for(int i=0;i<n;++i)
		cin>>x[i]>>y[i],mx=max(mx,abs(x[i])+abs(y[i]));
	for(int i=1;i<n;++i)
		if(((x[0]+y[0])^(x[i]+y[i]))&1)
			return cout<<-1<<Endl,0;
	if(!((x[0]^y[0])&1)) ans.pb(1);
	while((1LL<<m)<=mx) ans.pb(1<<m++);
	reverse(all(ans));
	cout<<(m=ans.size())<<Endl;
	for(int i=0;i<m;++i)
		cout<<ans[i]<<" \n"[i==m-1];
	string ch="LRDU";
	function<void(int,int)>go=[&](int x,int y)
	{
		string s(m,'a');
		int a[2]={x,y};
		for(int i=0;i<m;++i)
		{
			int c=0,d=0,t;
			if(abs(a[1])>abs(a[0])) c=1;
			if(a[c]>0) d=1;
			s[i]=ch[c<<1|d];
			a[c]=d?a[c]-ans[i]:a[c]+ans[i];
		}
		cout<<s<<Endl;
	};
	for(int i=0;i<n;++i)
		go(x[i],y[i]);
}