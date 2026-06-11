#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
    int x;
    char c;
    int f=1;
    while((c=getchar())!='-' && (c>'9' || c<'0'));
    if(c=='-') f=-1,c=getchar();
    x=c^'0';
    while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
    return x*f;
}
inline ll readll(){
    ll x;
    char c;
    int f=1;
    while((c=getchar())!='-' && (c>'9' || c<'0'));
    if(c=='-') f=-1,c=getchar();
    x=c^'0';
    while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
    return x*f;
}
const int maxn=2e5+10;
int a[maxn];
ll sum[maxn];
int main(){
	int n=read(),m=read();
	ll ans=1e18;
	REP(i,1,n) a[i]=read(),sum[i]=sum[i-1]+a[i];
	REP(i,1,n){
		ll res=0;
		REP(j,1,n/i+1){
			res+=(sum[n-(j-1)*i]-sum[max(n-j*i,0)])*(j==1?5:(j+1)*2-1);
			if(res>ans) break;
		}
		res+=(ll)i*m;
		chkmin(ans,res);
	}
	printf("%lld\n",ans+(ll)n*m);
    return 0;
}