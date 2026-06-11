#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005];
int st[200005],c[200005],top;
bool check(int k)
{
	top=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			if(st[top]!=1)++top;
			st[top]=1;
			c[top]=a[i];
			continue;
		}
		while(c[top-1]>=a[i])top--;
		c[top]=a[i];
		if(st[top]==k)
		{
			int num=c[top--];
			if(!top)return 0;
			if(c[top]!=c[top-1]+1)
			{
				c[top]--;
				top++;
				c[top]=c[top-1]+1;
				st[top]=st[top-1];
			}
			st[top]++;
			if(st[top]==st[top-1])c[top-1]=c[top],top--;
			st[++top]=1;
			c[top]=num;
		}
		else
		{
			if(c[top]!=c[top-1]+1)
			{
				c[top]--;
				top++;
				c[top]=c[top-1]+1;
				st[top]=st[top-1];
			}
			st[top]++;
			if(st[top]==st[top-1])c[top-1]=c[top],top--;
		}
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}