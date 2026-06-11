#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x[1010],y[1010];
int ansa[40],ansb[40];
void work(int w,int ans[])
{
	int f=1;
	if(w<0)f=-1,w=-w;
	for(int i=30,j;i>=0;--i)
		if(!(w>>i&1))
		{
			j=i-1;
			while(~j&&!(w>>j&1))--j;
			if(~j)
			{
				for(int k=j;k<i;++k)ans[k]=-1;ans[i]=1;
			}
			else
			{
				for(int k=0;k<i;++k)ans[k]=-1;ans[i]=1;ans[31]=-1;
			}
			i=j;
		}
		else ans[i]=1;
	if(f==-1)for(int i=0;i<=31;++i)ans[i]=-ans[i];
}
int main()
{
	scanf("%d",&n);
	int a,b;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&a,&b);
		x[i]=a+b,y[i]=a-b;
	}
	for(int i=2;i<=n;++i)if((x[i]&1)!=(x[1]&1))return printf("-1"),0;
	int m=31+(x[1]%2==0);
	printf("%d\n",m);
	for(int i=0;i<=30;++i)printf("%d ",1<<i);
	if(x[1]%2==0)printf("%d ",1);
	printf("\n");
	for(int i=1;i<=n;++i)
	{
		work(x[i],ansa);
		work(y[i],ansb);
		for(int j=0;j<m;++j)
		{
			if(ansa[j]==1)
			{
				if(ansb[j]==1)putchar('R');
				else putchar('U');
			}
			else
			{
				if(ansb[j]==1)putchar('D');
				else putchar('L');
			}
		}
		putchar('\n');
	}
	return 0;
}
