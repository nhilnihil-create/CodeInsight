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
const int N=1<<18;
int main()
{IOS;
	int n;cin>>n;
	vector<ll>s(n+1,0);
	auto calc=[&](int l,int o,int r)
	{
		ll t[4]={s[l],s[o]-s[l],s[r]-s[o],s[n]-s[r]};
		sort(t,t+4);
		return t[3]-t[0];
	};
	for(int i=1,x;i<=n;++i)
		cin>>x,s[i]=s[i-1]+x;
	ll ans=1LL<<61;
	for(int l=1,o=2,r=3;o<n-1;++o)
	{
		while(l<o-1&&abs(s[o]-2*s[l])>abs(s[o]-2*s[l+1]))
			++l;
		while(r<n-1&&abs(s[n]-2*s[r]+s[o])>abs(s[n]-2*s[r+1]+s[o]))
			++r;
		ans=min(ans,calc(l,o,r));
	}
	cout<<ans<<Endl;
}