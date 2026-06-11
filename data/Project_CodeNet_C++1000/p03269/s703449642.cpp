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
	int L;cin>>L;
	int n=1;
	for(int i=0;i<20;++i)
		if((L>>i)&1)
			n=i+1;
	typedef array<int,3> ar3;
	vector<ar3>ans;
	for(int i=1,t=1;i<n;++i,t<<=1)
	{
		ans.pb({i,i+1,0});
		ans.pb({i,i+1,t});
	}
	for(int i=0,t=1<<n-1;i<n-1;++i)
		if((L>>i)&1)
		{
			ans.pb({i+1,n,t});
			t+=1<<i;
		}
	cout<<n<<' '<<ans.size()<<Endl;
	for(auto c:ans)
		for(int i=0;i<3;++i)
			cout<<c[i]<<" \n"[i==2];
}