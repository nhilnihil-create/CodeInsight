#include<bits/stdc++.h>
#define re register
#define ui unsigned int
#define ull unsigned long long
int a[200100],f[200100],q[200100],nm[200100],ta,n;
bool check(re int mid)
{
	ta=0;
	for(re int i=2;i<=n;i++)if(a[i]<=a[i-1])
	{
		if(mid==0)return 0;
		while(q[ta]>a[i])ta--;
		re int x=a[i];
		for(;x;x--)
		{
			if(!ta||q[ta]!=x){q[++ta]=x,nm[ta]=1;break;}
			else if(nm[ta]<mid){nm[ta]++;break;}
			else ta--;
		}
		//printf("***%d %d %d\n",i,x,ta);
		if(!x)return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	f[0]=1e9;
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	re int l=0,r=n,mid;
	for(mid=(l+r)/2;l<r;mid=(l+r)/2)
	{
		//printf("**%d %d %d\n",l,r,mid);
		if(check(mid))r=mid;else l=mid+1;
	}
	printf("%d\n",l+1);
}