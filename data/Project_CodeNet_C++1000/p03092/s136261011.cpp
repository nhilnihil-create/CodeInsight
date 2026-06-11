//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
#define N 5010
ll f[N][N]; int a[N];
void upd(ll &x,ll y){x=x<y?x:y;}
int main()
{
	int n=read(),A=read(),B=read();
	for(int i=1;i<=n;i++)	a[i]=read();
	memset(f,48,sizeof(f)); f[0][0]=0;
	for(int i=1;i<=n;i++)	for(int j=0;j<=n;j++)
		if(a[i]>j)	upd(f[i][j],f[i-1][j]+A),upd(f[i][a[i]],f[i-1][j]);
		else	upd(f[i][j],f[i-1][j]+B);
	for(int i=1;i<=n;i++)	upd(f[n][0],f[n][i]);
	printf("%lld\n",f[n][0]);
	return 0;
}
