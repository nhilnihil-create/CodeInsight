#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	long long s=0LL;
	for (int i = 0; i < n; ++i)
	{
		s+=(long long)a[i];
	}
	bitset<4000005> dp;
	dp[0]=1;
	for (int i = 0; i < n; ++i)
	{
		dp|=(dp<<a[i]);
	}
	for (long long i = (s+1LL)/2LL; i < 4000005; ++i)
	{
		if (dp[i])
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
