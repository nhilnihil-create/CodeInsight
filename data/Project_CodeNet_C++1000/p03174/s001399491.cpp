#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
const int maxmask=2097155;
const int mod=1e9+7;
bool valid[maxn][maxn];
int num[maxmask],my_popcount[maxmask];
vector<int> useful[maxn];
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
		for(int j=1;j<=n;j++)
			scanf("%d",&valid[i][j]);
	for(int i=0;i<(int)(1<<n);i++)
	{
		my_popcount[i]=my_popcount[i>>1]+(i&1);
		useful[my_popcount[i]].push_back(i);
	}
	num[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<(int)useful[i].size();j++)
		{
			int now=useful[i][j];
			for(int k=1;k<=n;k++)
				if(valid[i][k]&&(now&(1<<(k-1))))
				{
					int pre=now&(~(1<<(k-1)));
					num[now]=num[now]+num[pre]-(num[now]+num[pre]>=mod)*mod;
				}
		}
	int ans=num[(1<<n)-1];
	printf("%d\n",ans);
	return 0;
}
