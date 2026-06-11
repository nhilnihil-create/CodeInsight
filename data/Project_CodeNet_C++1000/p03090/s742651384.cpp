#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
using namespace std;
int n;
vector <pair<int,int> > e;
signed main()
{
	scanf("%d",&n);
	if (n&1)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (i+j==n) continue;
				e.push_back(m_k(i,j));
			}
		}
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (i+j==n+1) continue;
				e.push_back(m_k(i,j));
			}
		}
	}
	printf("%d\n",(int)e.size());
	for (int i=0;i<(int)e.size();i++) printf("%d %d\n",e[i].first,e[i].second);
}