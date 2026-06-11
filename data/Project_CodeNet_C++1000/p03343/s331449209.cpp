//杀害兔子太好了，没有了。
#include<cstdio>
#include<iostream>
#include<algorithm>
#define MN 2005
int n,k,q,a[MN],num[MN],cnt,ans=1047483648;
bool check(int l,int r)
{
	int now=0;
	for(int i=1,j;i<=n;i++)
	{
		if(a[i]>=l)
		{
			int tot=0;
			for(j=i;j<=n&&a[j]>=l;j++) if(a[j]<=r) tot++;
			now+=std::min(std::max(j-i-k+1,0),tot);
			i=j;
		}
	}
	return now>=q;
}
int main()
{
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),num[i]=a[i];
	std::sort(num+1,num+n+1);
	cnt=std::unique(num+1,num+1+n)-num-1;
	for(int i=1;i<=cnt;i++)
	{
		int l=0,r=cnt-i;
		while(l<=r)
		{
			int mid=l+r+1>>1;
			if(check(num[i],num[i+mid])) {ans=std::min(ans,num[i+mid]-num[i]);r=mid-1;}
			else l=mid+1;
		}
	}
	printf("%d\n",ans);
}