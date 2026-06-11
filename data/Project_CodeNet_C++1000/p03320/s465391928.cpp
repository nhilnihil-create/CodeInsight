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
	return a*B<b*A||(a*B==b*A&&a<b);
}

ll a[100],m,z;
void split(ll x){
	for(m=0;x;x/=10)a[++m]=x%10;
}
int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
#endif
	ll k,w=1;
	for(cin>>k;k;k--){
		Pr("w=%lld\n",w); 
		split(w); 
		for(ll i=1,t=w,z=1;i<=m;++i,z=z*10){
			t+=(9-a[i])*z;
			Pr("t=%lld\n",t); 
			if(small(t,w))w=t;
		}
		printf("%lld\n",w);
		w=w+1;
	}
	return 0;
}