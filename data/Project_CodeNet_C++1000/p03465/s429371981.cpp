#include<cstdio>
#include<bitset>
using namespace std;
int n,a[2005],w[4000005],cnt;
bitset<4000005>c;
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]);c[0]=1;
	for(int i=1;i<=n;++i) c|=c<<a[i];
	for(int i=0;i<=4000000;++i) if(c[i]) w[++cnt]=i;
	printf("%d",w[cnt/2+1]);
	return 0;
}