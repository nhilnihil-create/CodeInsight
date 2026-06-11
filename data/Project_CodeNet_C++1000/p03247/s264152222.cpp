#include<cstdio>
#include<algorithm>
using namespace std;
int n,X[1005],Y[1005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&X[i],&Y[i]);
	int fg=abs(X[1]+Y[1])&1;
	for(int i=2;i<=n;++i)
		if(fg!=(abs(X[i]+Y[i])&1))
			return puts("-1"),0;
	printf("%d\n",32-fg);
	for(int i=30;~i;--i)printf("%d ",1<<i);
	if(!fg){
		putchar('1');
		for(int i=1;i<=n;++i)++X[i];
	}
	puts("");
	for(int i=1;i<=n;++i){
		int x=X[i],y=Y[i];
		for(int j=30;~j;--j)
			if(abs(x)>=abs(y))
				if(x>0)putchar('R'),x-=1<<j;
				else putchar('L'),x+=1<<j;
			else
				if(y>0)putchar('U'),y-=1<<j;
				else putchar('D'),y+=1<<j;
		if(!fg)putchar('L');
		puts("");
	}
	return 0;
}
