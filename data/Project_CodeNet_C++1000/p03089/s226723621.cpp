#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,a[N];
vector <int> ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool bl=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>i)
		{
			bl=0;
			break;
		}
	}
	if (!bl)
	{
		printf("-1\n");
		return 0;
	}
	while ((int)ans.size()<n)
	{
		for (int j=n;j>=1;j--)
		{
			if (!a[j]) continue;
			int cnt=0;
			for (int k=1;k<=j;k++) cnt+=(a[k]!=0);
			if (cnt==a[j])
			{
				ans.push_back(a[j]);
				a[j]=0;
				break;
			}
		}
	}
	reverse(ans.begin(),ans.end());
	for (int i=0;i<(int)ans.size();i++) printf("%d\n",ans[i]);
}