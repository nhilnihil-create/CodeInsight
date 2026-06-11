#include<cstdio>
#include<algorithm>
int n,ans,a[200005],b[200005],x[200005],y[200005];
int can(int x,int y)
{
	return x&(1<<y);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=0;i<=28;i++)
	{
		for (int j=1;j<=n;j++) x[j]=a[j]%(1<<(i+1));
		for (int j=1;j<=n;j++) y[j]=b[j]%(1<<(i+1));
		std::sort(x+1,x+n+1);for (int j=1;j<=n/2;j++) std::swap(x[j],x[n-j+1]);
		std::sort(y+1,y+n+1);
		int l=1,r=0,cnt=0;
		while (l<=n&&!can(y[l]+x[1],i)&&(y[l]+x[1]<(1<<(i+1)))) ++l;
		while (r+1<=n&&!can(y[r+1]+x[1],i)&&(y[r+1]+x[1]<(1<<(i+1)))) ++r;
		for (int j=1;j<=n;j++)
		{
			while (l<=n&&!((y[l]+x[j])&(1<<i))&&(y[l]+x[j]<(1<<(i+1)))) ++l;
			while (r+1<=n&&((y[r+1]+x[j])&(1<<i))&&(y[r+1]+x[j]<(1<<(i+1)))) ++r;
//			printf("%d %d %d %d\n",i,j,l,r);
			if ((r-l+1)<0) continue;
			cnt=(cnt+(r-l+1))&1;
		}
		l=1,r=0;
		while (l<=n&&(y[l]+x[1]<(1<<(i+1)))) ++l;
		while (r+1<=n&&(y[r]+x[1]<(1<<(i+1)))) ++r;
		while (l<=n&&!can(y[l]+x[1],i)) ++l;
		while (r+1<=n&&!can(y[r+1]+x[1],i)) ++r;
		for (int j=1;j<=n;j++)
		{
			while (l<=n&&!((y[l]+x[j])&(1<<i))) ++l;
			while (r+1<=n&&((y[r+1]+x[j])&(1<<i))) ++r;
//			printf("%d %d %d %d\n",i,j,l,r);
			if ((r-l+1)<0) continue;
			cnt=(cnt+(r-l+1))&1;
		}
//		printf("%d\n",cnt);
		if (cnt) ans=ans+(1<<i);
	}
	printf("%d\n",ans);
}