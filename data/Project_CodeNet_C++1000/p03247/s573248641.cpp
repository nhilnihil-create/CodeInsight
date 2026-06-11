#include <bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
#define rll register ll
const int N=1e3+5;
int ax[N],ay[N];
ll p[N],q[N];
char ans[N];
inline bool check(rll x,rll y,rll s){
	return abs(x)+abs(y)<=s;
}
int main(){
	ri n,i,j,v1,v,d;
	rll x,y;
	scanf("%d",&n);
	d=0;
	for(i=1;i<=n;++i){
		scanf("%d%d",&ax[i],&ay[i]);
		v=abs(ax[i])+abs(ay[i]);
		if(i==1) v1=v&1;
		else if((v&1)!=v1)
			return puts("-1"),0;
		while(v>1ll<<d)
			++d;
	}
	if(v1)
		for(i=1;i<=d;++i) p[i]=1ll<<i-1,q[i]=1ll<<i;
	else{
		p[1]=1;q[1]=2;
		for(i=2;i<=d+1;++i)
			p[i]=1ll<<i-2,q[i]=1ll<<i-1;
		++d;
	}
	printf("%d\n",d);
	for(i=1;i<=d;++i) printf("%lld ",p[i]);
	puts("");
	for(i=1;i<=n;++i){
		x=ax[i];y=ay[i];
		for(j=d;j;--j)
			if(check(x-p[j],y,q[j-1]))
				x-=p[j],
				ans[j]='R';
			else if(check(x+p[j],y,q[j-1]))
				x+=p[j],
				ans[j]='L';
			else if(check(x,y-p[j],q[j-1]))
				y-=p[j],
				ans[j]='U';
			else
				y+=p[j], 
				ans[j]='D';
		ans[d+1]='\0';
		printf("%s\n",ans+1);
	}
	return 0;
}