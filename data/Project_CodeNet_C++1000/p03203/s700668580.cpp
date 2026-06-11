#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
typedef long long ll;
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
unordered_map<int,bool> mp[maxn];
int f[maxn];
struct point{
	int x,y;
}a[maxn];
int main(){
	int h=read(),w=read(),n=read();
	REP(i,1,n) a[i].x=read(),a[i].y=read(),mp[a[i].x][a[i].y]=1;
	REP(i,1,h){
		f[i]=f[i-1];
		if(!mp[i][f[i]+1]) ++f[i];
	}
	int ans=h;
	REP(i,1,n) if(f[a[i].x-1]>=a[i].y) chkmin(ans,a[i].x-1);
	printf("%d\n",ans);
	return 0;
}