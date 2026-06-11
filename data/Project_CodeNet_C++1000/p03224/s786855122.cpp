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
inline int check(int x){
	for(int i=1;i*(i-1)<=x;++i) if(i*(i-1)==x) return i;
	return 0;
}
const int maxn=1e3+10;
vector<int> ve[maxn];
int main(){
	int n=read();
	int m=check(2*n);
	if(!m) return printf("No\n"),0;
	printf("Yes\n%d\n",m);
	int Nw=1;
	REP(i,1,m)
		REP(j,i+1,m){
			ve[i].push_back(Nw);
			ve[j].push_back(Nw);
			++Nw;
		}
	REP(i,1,m){
		printf("%d ",ve[i].size());
		for(auto v:ve[i]) printf("%d ",v);
		putchar('\n');
	}
	return 0;
}