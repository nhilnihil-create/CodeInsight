#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char c[]="LDUR";
long long x[1005],y[1005];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		x[i]=a+b;
		y[i]=a-b;
	}
	bool ok=1;
	for(int i=1;i<=N;i++)if((x[i]&1)!=(x[1]&1))ok=0;
	if(!ok){puts("-1"); return 0;}
	bool t=!(x[1]&1);
	printf("%d\n",39+t);
	long long sum=0;
	if(t)printf("%d ",1),sum+=1;
	for(int i=0;i<39;i++)printf("%lld ",1ll<<i),sum+=1ll<<i;
	puts("");
	for(int i=1;i<=N;i++){
		x[i]+=sum;
		y[i]+=sum;
		if(t)putchar(c[0]);
		for(int j=1;j<=39;j++)
			putchar(c[( ( (x[i]>>j)&1 )<<1 )|( (y[i]>>j)&1 )]);
		puts("");
	}
	return 0;
}