#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

vector<pair<pair<int, int>, pair<int, int>>> out;
signed main(void)
{
	int h, w;
	long long cnt;
	cin >> h >> w;
	int s[h][w];

	rep(i, h)rep(j, w) cin >> s[i][j];
	cnt = 0;
	rep(i, h)
	{
		if (i % 2 == 0)
		{
			rep(j, w)
			{
				if (s[i][j] % 2 != 0)
				{
					if (j + 1 < w)
					{
						s[i][j + 1] += s[i][j]; 
						out.push_back(make_pair(make_pair(i + 1, j + 1),\
									make_pair(i + 1 , j + 2)));
					cnt++;
					}
					else if (i + 1 < h)
					{
						s[i + 1][j] += s[i][j];
						out.push_back(make_pair(make_pair(i + 1, j + 1),\
									make_pair(i + 2, j + 1)));
					cnt++;
					}
				}
			}
		}
		else
		{
			for(int j = w - 1; j >= 0; j--)
			{
				if (s[i][j] % 2 != 0)
				{
					if (j - 1 >= 0)
					{
						s[i][j - 1] += s[i][j]; 
						out.push_back(make_pair(make_pair(i + 1, j + 1),\
									make_pair(i + 1 , j)));
					cnt++;
					}
					else if (i + 1 < h)
					{
						s[i + 1][j] += s[i][j];
						out.push_back(make_pair(make_pair(i + 1, j + 1),\
									make_pair(i + 2, j + 1)));
					cnt++;
					}
				}
			}
		}
	}
	cout << cnt << endl;
	rep(i, cnt)
	{
		cout << out[i].first.first << " " << out[i].first.second << " ";
		cout << out[i].second.first << " " << out[i].second.second << endl;
	}
	return 0;
}
