#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010;

int n,odd,wd,bin[50];
char s[50];

struct P{ll x,y;}p[N];

int dx[6]={-1,1,0,0};
int dy[6]={0,0,-1,1};
char dr[6]={'R','L','U','D'};

inline ll as(ll x){return x<0?-x:x;}

inline void solve(P nw)
{
	int i,j,k;ll mn,res;
	for(i=wd;i;--i){
		mn=1e18;k=0;
		for(j=0;j<4;++j){
			res=max(as(nw.x+bin[i]*dx[j]),as(nw.y+bin[i]*dy[j]));
			if(res<mn) {mn=res;k=j;}
		}
		s[i]=dr[k];nw.x+=bin[i]*dx[k];nw.y+=bin[i]*dy[k];
	}
	for(i=1;i<=wd;++i) putchar(s[i]);
	puts("");
	//printf("%lld %lld\n",nw.x,nw.y);
}

int main(){
	int i,j;
	scanf("%d%lld%lld",&n,&p[1].x,&p[1].y);
	odd= ((p[1].x+p[1].y)%2+2)%2;
	for(i=2;i<=n;++i){
		scanf("%lld%lld",&p[i].x,&p[i].y);
		if(odd != ((p[i].x+p[i].y)%2+2)%2) break;
	}
	if(i<=n) {puts("-1");return 0;}
	bin[1]=1;
	for(i=2;i<=31;++i) bin[i]=bin[i-1]<<1;
	wd=31;if(!odd) bin[++wd]=1;
	printf("%d\n",wd);
	for(i=1;i<wd;++i) printf("%d ",bin[i]);
	printf("%d\n",bin[wd]);
	for(i=1;i<=n;++i) solve(p[i]);
	return 0;
}