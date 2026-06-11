#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 300000
int p[MN+5];
bool cmp(int a,int b){return a>b;}
int main()
{
	int n,a,b,i,j,k;
	scanf("%d%d%d",&n,&a,&b);
	if(a>n||b>n||b<(n+a-1)/a||b>n-a+1)return 0*puts("-1");
	for(i=1,k=n;i<=n;i+=a)for(j=min(n,i+a-1);j>=i;--j)p[j]=k--;
	for(i=(n+a-1)/a,j=n;i<b;++i,--j)if(j%a==1)--j;
	sort(p+j,p+n+1,cmp);
	for(i=1;i<=n;++i)printf("%d ",p[i]);
}