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
const int zero=1<<17;
int t[N],a[N],n;
int b[N],cc;
void add(int x,int v){for(;x<N;t[x]+=v,x+=lowbit(x));}
int sum(int x){int ret=0;while(x)ret+=t[x],x-=lowbit(x);return ret;}
int sum(int l,int r){return sum(r)-sum(l-1);}
ll calc(int x)
{
	int y=zero;
	ll ret=0;
	clr(t,0);
	add(zero,1);
	for(int i=1;i<=n;++i)
	{
		y+=(a[i]<=x?1:-1);
		ret+=sum(y-1);
		add(y,1);
	}
	return ret;
} 
int main()
{IOS;
	cin>>n;cc=0;
	for(int i=1;i<=n;++i)
		cin>>a[i],b[++cc]=a[i];
	sort(b+1,b+1+cc);
	cc=unique(b+1,b+1+cc)-b-1;
	int L=1,R=cc,mid;
	ll ans,tp;
	ll ok=1LL*(n+1)*n/4+1;
	while(R>=L)
	{
		mid=(L+R)>>1;
		if((tp=calc(b[mid]))>=ok)
			ans=b[mid],R=mid-1;
		else L=mid+1;
	}
	cout<<ans<<Endl;
}