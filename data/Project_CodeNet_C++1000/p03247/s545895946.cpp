#include <cstdio>
#include <algorithm>
#define max_n 1000
using namespace std;
long long x[max_n+1],y[max_n+1],ton[33];
void solve(long long x,long long y,int sz){
	for(int i=sz; /*printf("\n*%d %d|\n",x,y),*/~--i; labs(x)>labs(y)?(x<0?(putchar('L'),x+=ton[i]):(putchar('R'),x-=ton[i])):(y<0?(putchar('D'),y+=ton[i]):(putchar('U'),y-=ton[i])));
    puts("");
}
int main(){
	int n,sz;
    bool flg[2]={0,0};
    scanf("%d",&n);
    for(int i=0; ++i<=n; flg[(x[i]+y[i])&1]=1)
    	scanf("%lld%lld",x+i,y+i);
    if(flg[0]&&flg[1]){
    	puts("-1");
		return 0;
    }
    if(flg[1]){
        printf("%d\n",sz=32);
        for (int i=sz; --i; printf("%lld ",ton[i]=1LL<<i));
        printf("%lld\n",ton[0]=1);
    }
	else{
        printf("%d\n",sz=33);
        for (int i=sz; --i; printf("%lld ",ton[i]=1LL<<(i-1)));
        printf("%lld\n",ton[0]=1);
    }
    for(int i=0; ++i<=n; solve(x[i],y[i],sz));
    return 0;
}