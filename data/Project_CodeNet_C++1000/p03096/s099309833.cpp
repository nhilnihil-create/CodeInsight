#include<cstdio>
#include<cstdlib>
#include<cstring>
#define Mod 1000000007
#define Maxn 200010

int a[Maxn],f[Maxn],sm[Maxn];


int main()
{
	int n,m=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++) if(a[i]!=a[m]) a[++m]=a[i];
	memset(sm,0,sizeof(sm));
	// for(int i=0;i<=m;i++) f[i]=1;
	f[0]=1;
	for(int i=1;i<=m;i++)
	{
		f[i]=f[i-1];
		f[i]=(f[i]+sm[a[i]])%Mod;
		sm[a[i]]=(sm[a[i]]+f[i-1])%Mod;
	}
	printf("%d\n",f[m]);
	return 0;
}
