#include <bits/stdc++.h>
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define mem(a,k) memset(a,k,sizeof(a))
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

#define Pr(f,...) //fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)

typedef long long ll;

template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}

const int N=1e5+50; 

/*
const int N=;

int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }
*/

int n,L[N],R[N];
ll ans;
int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	freopen("dat.in","r",stdin);
//	freopen("my.out","w",stdout);
#endif
	scanf("%d",&n); 
	rep(i,1,n)scanf("%d%d",L+i,R+i);
	sort(L,L+n+1),reverse(L,L+n+1);
	sort(R,R+n+1);
	rep(i,0,n)ans+=max(0,L[i]-R[i]); 
	printf("%lld\n",ans*2);
	return 0;
}