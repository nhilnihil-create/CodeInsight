#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100010
int n,a[N],bin[N];
struct Edge {int x,y,z;}e[N];
int main()
{
	scanf("%d",&n),n--,bin[0]=1;
	for(int i=1;i<=20;i++) bin[i]=bin[i-1]<<1;
	int k=0,m=n,tot=0; bool flag=false;
	while(m) k++,flag|=m%2==0,m/=2;
	if(!flag)
	{
		printf("%d ",k+1);
		for(int i=1;i<=k;i++)
		{
			tot++,e[tot].x=i,e[tot].y=i+1,e[tot].z=bin[i-1],
			tot++,e[tot].x=i,e[tot].y=i+1,e[tot].z=0;
		}
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++) printf("%d %d %d\n",e[i].x,e[i].y,e[i].z);
		return 0;
	} printf("%d ",k);
	for(int i=1;i<k;i++)
	{
		tot++,e[tot].x=i,e[tot].y=i+1,e[tot].z=bin[k-i-1];
		tot++,e[tot].x=i,e[tot].y=i+1,e[tot].z=0;
	}
	int cnt=0;
	for(int i=0;i<=20;i++) if(n&bin[i]) a[++cnt]=i;
	int pre=bin[a[cnt]];
	for(int i=cnt-1;i;i--) tot++,e[tot].x=1,e[tot].y=k-a[i],e[tot].z=pre,pre+=bin[a[i]];
	tot++,e[tot].x=1,e[tot].y=k,e[tot].z=n;
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d %d %d\n",e[i].x,e[i].y,e[i].z);
}