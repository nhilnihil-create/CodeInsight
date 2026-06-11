#include<cstdio>
#include<algorithm>
int n,p[200005],q[200005];
long long a[200005],f[200005],ans=1000000000000000;
long long solve(int l,int r){return f[r]-f[l-1];}
long long make(int k1,int k2,int k3)
{
	if (!((1<=k1)&&(k1<k2)&&(k2<k3)&&(k3<n))) return 1000000000000000;
	long long xx=std::max(std::max(std::max(solve(1,k1),solve(k1+1,k2)),solve(k2+1,k3)),solve(k3+1,n));
	long long yy=std::min(std::min(std::min(solve(1,k1),solve(k1+1,k2)),solve(k2+1,k3)),solve(k3+1,n));
	return xx-yy;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	int k=1;
	p[1]=1;
	for (int i=2;i<=n;i++)
	{
		while (solve(1,k)<solve(k+1,i)) ++k;
		p[i]=k;
	}
	k=n;
	q[n]=n;
	for (int i=n-1;i>=1;i--)
	{
		while (solve(k,n)<solve(i,k-1)) --k;
		q[i]=k;
	}
	for (int i=1;i<=n;i++)
	{
		ans=std::min(ans,make(p[i],i,q[i+1]-1));
		ans=std::min(ans,make(p[i]-1,i,q[i+1]-1));
		ans=std::min(ans,make(p[i],i,q[i+1]));
		ans=std::min(ans,make(p[i]-1,i,q[i+1]));
	}
	printf("%lld\n",ans);
	return 0;
}
