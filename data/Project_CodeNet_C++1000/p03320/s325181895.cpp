#include <bits/stdc++.h>
#define pb push_back
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
	char C;
	for(C=getchar();!isdigit(C);C=getchar()); 
	for(;isdigit(C);C=getchar())x=x*10+C-'0'; 
}

bool small(ll a,ll b){
	ll A=0,B=0,x;
	for(x=a;x;x/=10)A+=x%10;
	for(x=b;x;x/=10)B+=x%10;
	return a*B<=b*A;
}

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
#endif
	ll n,p=0,i;
	for(cin>>n,i=1;n;){
		p+=i;
		if(small(p,p+i))printf("%lld\n",p),--n;
		else p-=i,i*=10;
	}
	return 0;
}