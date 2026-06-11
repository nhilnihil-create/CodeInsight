#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1005;
int n,m;
LL x[N],y[N],d[N];
char ch[2];
int t[N],s=0;
int f1=0,f2=0;
void solve(LL x,LL y){
	for (int i=1;i<=m;i++){
		if (y>=abs(x))
			putchar('U'),y-=d[i];
		else if (y<=-abs(x))
			putchar('D'),y+=d[i];
		else if (x>=abs(y))
			putchar('R'),x-=d[i];
		else
			putchar('L'),x+=d[i];
	}
	if (x!=0||y!=0)
		puts("ERROR");
	puts("");
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		if ((x[i]+y[i])%2==0)
			f1=1;
		else
			f2=1;
	}
	if (f1&&f2)
		return puts("-1"),0;
	m=40;
	d[m]=d[m-1]=d[m-2]=d[m-3]=1;
	for (int i=m-4;i>=1;i--)
		d[i]=d[i+1]*2;
	if (f2)
		m--;
	printf("%d\n",m);
	for (int i=1;i<=m;i++)
		printf("%lld ",d[i]);
	puts("");
	for (int i=1;i<=n;i++)
		solve(x[i],y[i]);
	return 0;
}