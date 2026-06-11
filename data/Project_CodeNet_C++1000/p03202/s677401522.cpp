#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
bool check(int m)
{
	vector<pair<int,int> > v;
	for (int i=2;i<=n;i++)
	{
		if (a[i]<=a[i-1])
		{
			while (!v.empty() && v.back().first>a[i])
			v.pop_back();
			int tmp=a[i];
			while (!v.empty() && v.back().first==tmp && v.back().second==m)
			{
				v.pop_back();
				tmp--;
			}
			if (!tmp)
			return 0;
			if (v.empty() || v.back().first!=tmp)
			v.push_back({tmp,2});
			else
			v[v.size()-1].second++;
		}
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	bool one=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		one&=(a[i]>a[i-1]);
	}
	if (one)
	{
		printf("1");
		return 0;
	}
	int st=2,en=n;
	while (st!=en)
	{
		int mid=(st+en)/2;
		if (check(mid))
		en=mid;
		else
		st=mid+1;
	}
	printf("%d",st);
}