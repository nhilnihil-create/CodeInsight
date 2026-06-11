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
#define double long double
int S(ll n){
	int res=0;
	while(n){
		res+=n%10;
		n/=10;
	}
	return res;
}
double Calc(ll n,int k){
	REP(i,1,k) n/=10;
	REP(i,1,k) n=n*10+9;
	return (double)n/S(n);
}
ll f(ll x){
	int k=0,res=0;
	ll n=x;
	while(n) res++,n/=10;
	n=res;
	double Max=Calc(x,0);
	res=0;
	REP(i,0,n) if(chkmin(Max,Calc(x,i))) res=i;
	k=res;
	REP(i,1,k) x/=10;
	REP(i,1,k) x=x*10+9;
	return x;
}
int main(){
	int k=read();
	ll lst=0;
	while(k--){
		lst++;
		printf("%lld\n",lst=f(lst));
	}
	return 0;
}
