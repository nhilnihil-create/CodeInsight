#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 300005

using namespace std;
typedef long long int ll;

int sz[SIZE];

int main()
{
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	if((ll) a*(ll) b<(ll) n||a+b>n+1)
	{
		puts("-1");
	}
	else
	{
		int zan=n;
		for(int i=0;i<a;i++)
		{
			sz[i]=1;
			zan--;
		}
		for(int i=0;i<a;i++)
		{
			sz[i]+=zan;
			zan=max(0,sz[i]-b);
			sz[i]=min(sz[i],b);
		}
		int start=0;
		for(int i=0;i<a;i++)
		{
			for(int j=sz[i]-1;j>=0;j--) printf("%d ",start+j+1);
			start+=sz[i];
		}
		puts("");
	}
	return 0;
}
