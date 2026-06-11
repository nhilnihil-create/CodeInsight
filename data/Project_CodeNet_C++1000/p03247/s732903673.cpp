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
const int maxn=1000+10;
struct point{
	ll x,y;
}a[maxn];
char mp[4]={'L','R','D','U'};
int b;
void work(int times,ll x,ll y){
	ll u=(1ll<<times);
	if(y>=u) putchar('U'),y-=u;
	else if(y<=-u) putchar('D'),y+=u;
	else if(x>=u) putchar('R'),x-=u;
	else if(x<=-u) putchar('L'),x+=u;
	else{
		if(abs(x)>abs(y)){
			if(x<0) putchar('L'),x+=u;
			else putchar('R'),x-=u;
		}
		else{
			if(y<0) putchar('D'),y+=u;
			else putchar('U'),y-=u;
		}
	}
	if(times!=0) work(times-1,x,y);
}
int main(){
	int n=read();
	REP(i,1,n) a[i].x=read(),a[i].y=read();
	b=(a[1].x+a[1].y+(ll)2e9)%2;
	bool flag=1;
	REP(i,2,n) if((a[i].x+a[i].y+(ll)2e9)%2!=b) flag=0;
	if(!flag) return printf("-1\n"),0;
	printf("%d\n",32-b);
	DREP(i,30,0) printf("%lld ",(1ll<<(ll)i));
	if(!b){
		printf("%d ",1);
		REP(i,1,n) a[i].x+=1;
	}
	putchar('\n');
	REP(i,1,n){
		work(30,a[i].x,a[i].y);
		if(!b) printf("L");
		putchar('\n');
	}
    return 0;
}