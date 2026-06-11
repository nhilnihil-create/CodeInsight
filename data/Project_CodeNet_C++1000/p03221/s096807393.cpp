#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	map<int, int> si[100001];
	int n, m;
	cin >> n >> m;
	int p, y;
	pair<int, int> input[100001];
	for (int i = 0; i < m; ++i)
	{
		cin >> p >> y;
		si[p][y] = 1;
		input[i] = make_pair(p, y);
	}
	for (int i = 0; i <= n; ++i)
	{
		int count = 1;
		for (auto itr = si[i].begin(); itr != si[i].end(); ++itr)
		{
			itr->second = count++;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		printf("%06d%06d\n", input[i].first, si[input[i].first][input[i].second]);
	}
	return 0;
}