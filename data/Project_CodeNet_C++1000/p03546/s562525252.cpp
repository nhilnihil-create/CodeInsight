#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h,w;
	cin >> h >> w;

	vector<vector<int>> dp(10,vector<int>(10));
	for (int i=0;i<10;++i)
	{
		for (int j=0;j<10;++j)
		{
			cin >> dp[i][j];
		}
	}

	vector<vector<int>> a(h,vector<int>(w));
	vector<int> count(10);
	for (int i=0;i<h;++i)
	{
		for (int j=0;j<w;++j)
		{
			int d;
			cin >> d;
			a[i][j]=d;
			if (d!=-1)
			{
				++count[d];
			}
		}
	}

	for (int k=0;k<10;++k)
	{
		for (int i=0;i<10;++i)
		{
			for (int j=0;j<10;++j)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}

	int64_t sum=0;
	for (int i=0;i<10;++i)
	{
		sum+=(int64_t)count[i]*dp[i][1];
	}
	cout << sum << endl;
}





