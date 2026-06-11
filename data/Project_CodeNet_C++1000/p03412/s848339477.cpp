#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n],b[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>b[i];
	}
	int ans=0;
	for (int i = 0; i < 30; ++i)
	{
		vector<int> x(n),y(n);
		for (int j = 0; j < n; ++j)
		{
			x[j]=a[j]%(1<<(i+1));
			y[j]=b[j]%(1<<(i+1));
		}
		sort(y.begin(), y.end());
		long long cnt=0LL;
		for (int j = 0; j < n; ++j)
		{
			if ((1<<i)-x[j]>=0)
			{
				cnt+=(long long)(lower_bound(y.begin(), y.end(),(1<<(i+1))-x[j])-lower_bound(y.begin(), y.end(),(1<<i)-x[j]));
			}
			else
			{
				cnt+=(long long)(lower_bound(y.begin(), y.end(),(1<<(i+1))-x[j])-y.begin());
				cnt+=(long long)(lower_bound(y.begin(), y.end(),(1<<(i+1)))-lower_bound(y.begin(), y.end(),(3<<i)-x[j]));
			}
		}
		if (cnt&1LL)
		{
			ans+=(1<<i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
