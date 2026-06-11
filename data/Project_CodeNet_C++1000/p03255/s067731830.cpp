#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=(s);i<(t);++i)
#define per(i,s,t) for(int i=((t)-1);i>=s;--i)
#define repb(i,s,t) for(int i=(s);i<=(t);++i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
#define mst(a,b) memset(a,b,sizeof(a))
#define mcpy(des,sor) memcpy(des,sor,sizeof(sor))
#define dd(x) cout<<#x<<'='<<x<<' '
#define de(x) cout<<#x<<'='<<x<<'\n'
#define fi first
#define se second
#define sq(x) ((x)*(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

const int inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
const db eps = 1e-8;

char io[1<<15],*is=io,*ie=io+1;
#define rd if(++is==ie)ie=(is=io)+fread(io,1,sizeof(io),stdin)
template<class T>
inline bool Cin(T &a){
	a=0;bool s=0;
	if(is==ie)return 0;
	do{rd;if(*is=='-')s=1;}while(!isdigit(*is)&&is!=ie);
	if(is==ie)return 0;
	do{(a*=10)+=*is&15;rd;}while(isdigit(*is)&&is!=ie);
	if(s)a=-a;;return 1;}

inline int Gets(char a[]){
	int p=0;
	if(is==ie)return 0;
	do rd; while(!isgraph(*is)&&is!=ie);
	if(is==ie)return 0;
	do {a[p++]=*is;rd;}while(isgraph(*is)&&is!=ie);
	a[p]=0;return p;}

#define maxn 200005
ll x[maxn],s[maxn];

int main()
{
	mst(x,0);mst(s,0);
	int n,p;ll X,t,ans=~0ull>>1;
	Cin(n);Cin(X);
	repb(i,1,n)
	{
		Cin(x[i]);
		s[i]=s[i-1]+x[i];
	}
	for(int k=n;k>=1;--k)
	{
		t=0;p=n;
		repb(i,1,n/k+1)
		{
			if(i==1)t+=(s[max(p,0)]-s[max(0,p-k)])*5;
			else t+=(s[max(p,0)]-s[max(0,p-k)])*(2*i+1);
			p-=k;
			if(t>=ans)break;
		}
		ans=min(ans,X*(n+k)+t);
	}
	printf("%lld\n",ans);
}