#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>

#define Mod 1000000007
using namespace std;

int a[200010],g[200010],f[200010],n,as;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int n_=n;n=1;
	for (int i=1;i<=n_;i++) if(a[i]!=a[n]) a[++n]=a[i];
	f[0]=1;
	for (int i=1;i<=n;i++){
		f[i]=(g[a[i]]+f[i-1])%Mod;
		g[a[i]]=(g[a[i]]+f[i-1])%Mod;
	}
	printf("%d\n",f[n]);
}