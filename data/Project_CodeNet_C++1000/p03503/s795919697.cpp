#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int n;
	cin >> n;

	vector<vector<int>> F(n, vector<int>(10));
	vector<vector<int>> P(n, vector<int>(11));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> F[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 11; j++)
			cin >> P[i][j];
	}

	int ans = -1e9;
	for (int i = 1; i < (1 << 10); i++)
	{
		bitset<10> S(i);
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			for (int k = 9; k >= 0; k--)
			{
				if (S[k] && F[j][k])
					cnt++;
			}
			sum += P[j][cnt];
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}

