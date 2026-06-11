#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 1005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,A[N],B[N],flag1,flag2,ans[N];
void Solve(int x,int y)
{
	for(int i=1;i<=m;i++)
	{
		if(abs(x)>abs(y)) if(x>0) putchar('R'),x-=ans[i];else putchar('L'),x+=ans[i];
		else if(y>0) putchar('U'),y-=ans[i];else putchar('D'),y+=ans[i];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&A[i],&B[i]),flag1|=(A[i]+B[i])&1,flag2|=~(A[i]+B[i])&1;
	if(flag1&&flag2) return puts("-1"),0;
	for(int i=30;~i;i--) ans[++m]=1<<i;
	if(flag2) ans[++m]=1;
	printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);puts("");
	for(int i=1;i<=n;i++) Solve(A[i],B[i]),puts("");
	return 0;
}