#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
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
const int N=2e5+50;
int n,m,q[N],h,t,deg[N][2];
char s[N];
vector<int> g[N];

bool chk(int v){return deg[v][1]&&deg[v][0]; }
int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
#endif
	read(n),read(m); 
	scanf("%s",s+1);
	rep(i,1,m){
		int u,v;
		read(u),read(v);
		g[u].pb(v),g[v].pb(u);
		deg[v][s[u]-'A']++;
		deg[u][s[v]-'A']++;
	}
	rep(i,1,n)Pr("%d,%d\n",deg[i][0],deg[i][1]);
	rep(i,1,n)if(!chk(i))q[t++]=i;
	Pr("t=%d\n",t);
	while(h<t){
		int v=q[h++];
		Pr("v=%d\n",v);
		for(int d:g[v]){
			bool o=chk(d);
			--deg[d][s[v]-'A'];
			if(o&&!chk(d))q[t++]=d;
		}
	}
	puts(t==n?"No":"Yes");
	return 0; 
}
