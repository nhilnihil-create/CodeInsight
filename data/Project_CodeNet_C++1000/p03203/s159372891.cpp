#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,h,w,ans,minp[200005];
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	ans=h;
	for(int i=1;i<=h;i++)minp[i]=w+1;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		minp[x]=min(minp[x],y);
	}
	int now=0;
	for(int i=1;i<=h;i++)
	{
		if(minp[i]<=now)
		{
			printf("%d\n",i-1);
			return 0;
		}
		if(minp[i]>now+1)now++;
	}
	printf("%d\n",h);
	return 0;
}