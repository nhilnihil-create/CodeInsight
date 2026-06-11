#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	//(ai,bi)をペアとして入力
	vector<pair<int, int>> k;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		k.push_back({ a,b });
	}
	//並び変え
	sort(k.begin(), k.end());

	

	int start,ans;
	ans = 0;
	start = n;
	for (int i = m-1; i>=0 ; i--)
	{
		if (start >= k[i].second)
		{
			ans++;
			start = k[i].first;
		}

	}

	cout << ans;

	return 0;
}