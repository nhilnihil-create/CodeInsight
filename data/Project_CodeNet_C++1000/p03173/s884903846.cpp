#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=405;
ll a[maxn],minn[maxn][maxn],front[maxn];
void fl()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
int main()
{
//    fl();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		front[i]=front[i-1]+a[i];
	}
	memset(minn,0x3f,sizeof(minn));
	for(int i=1;i<=n;i++)
		minn[i][i]=0;
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int l=i,r=i+len-1;
			for(int b=l;b<r;b++)
				minn[l][r]=min(minn[l][r],minn[l][b]+minn[b+1][r]);
			minn[l][r]+=front[r]-front[l-1];
		}
	printf("%lld\n",minn[1][n]);
	return 0;
}
