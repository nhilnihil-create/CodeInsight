#include<bits/stdc++.h>
using namespace std;
const int N=5002;
int n,A,B,a[N];
long long f[N],tot;
int main()
{
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[n+1]=n+1,n++;
	memset(f,63,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		tot=0;
		for(int j=i-1;~j;j--)
		{
			if (a[j]<a[i]) f[i]=min(f[i],f[j]+tot),tot+=B;
			else tot+=A;
		}
		//cout<<i<<' '<<f[i]<<endl;
	}
	printf("%lld",f[n]);
	return 0;
}
