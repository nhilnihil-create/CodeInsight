#include <bits/stdc++.h>
using namespace std;
int n;
int x,rem,ans;
int a[15];
int mul[15];
vector<int>q;
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		a[x]++;
	}
	a[0]++;
	ans=0;
	mul[1]=1;
	for(int i=2;i<15;i++)
	{
		mul[i]=mul[i-1]*2;
	}
	if(a[0]>1||a[12]>1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<12;i++)
	{
		if(a[i]>2)
		{
			printf("0\n");
			return 0;
		}
	}
	for(int i=0;i<mul[13];i++)
	{
		q.clear();
		q.push_back(0);
		rem=24;
		for(int j=1;j<=12;j++)
		{
			if(a[j]==0)
			{
				continue;
			}
			else if(a[j]==1)
			{
				if((i&mul[j])==mul[j])
				{
					q.push_back(j);
				}
				else
				{
					q.push_back(24-j);
				}
			}
			else
			{
				q.push_back(j);
				q.push_back(24-j);
			}
		}
		sort(q.begin(),q.end());
		for(int j=1;j<q.size();j++)
		{
			for(int k=0;k<j;k++)
			{
				rem=min(rem,q[j]-q[k]);
				rem=min(rem,24-q[j]+q[k]);
			}
		}
		ans=max(ans,rem);
	}
	printf("%d\n",ans);
	return 0;
}