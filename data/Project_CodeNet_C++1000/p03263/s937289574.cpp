#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int h, w;
	int a[501][501] = {};
	vector<pair<pair<int, int>, pair<int, int>>> ans;
	cin >> h >> w;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < h; ++i)
	{
		if (i % 2)
		{
			for (int j = w-1; j > 0; --j)
			{
				if(a[i][j] % 2)
				{
					a[i][j] -= 1;
					a[i][j-1] += 1;
					ans.push_back(make_pair(make_pair(i, j), make_pair(i, j-1)));
				}
			}
			if(a[i][0] % 2 && i != h - 1)
			{
				a[i][0] -= 1;
				a[i+1][0] += 1;
				ans.push_back(make_pair(make_pair(i, 0), make_pair(i+1, 0)));
			}
		}
		else
		{
			for (int j = 0; j < w - 1; ++j)
			{
				if(a[i][j] % 2)
				{
					a[i][j] -= 1;
					a[i][j+1] += 1;
					ans.push_back(make_pair(make_pair(i, j), make_pair(i, j+1)));
				}
			}
			if(a[i][w-1] % 2 && i != h - 1)
			{
				a[i][w-1] -= 1;
				a[i+1][w-1] += 1;
				ans.push_back(make_pair(make_pair(i, w-1), make_pair(i+1, w-1)));
			}
		}
	}
	cout << ans.size() << endl;
	for (auto it = ans.begin(); it != ans.end(); ++it)
	{
		cout << (*it).first.first+1 << " " << (*it).first.second+1 << " " << (*it).second.first+1 << " " << (*it).second.second+1 << endl;
	}
	return 0;
}