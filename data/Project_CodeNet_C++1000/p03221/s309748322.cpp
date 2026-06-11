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
	int N, M;
	cin >> N >> M;

	vector<vector<int>> C(M, vector<int>(3));
	for (int i = 0; i < M; i++)
	{
		cin >> C[i][0] >> C[i][1];
		C[i][2] = i;
	}

	sort(all(C));
	int cnt = 0, n = 0;
	for (int i = 0; i < M; i++)
	{
		if (n != C[i][0])
		{
			n = C[i][0];
			cnt = 1;
		}
		else
			cnt++;
		C[i][1] = cnt;
		int tmp = C[i][2];
		C[i][2] = C[i][0];
		C[i][0] = tmp;
	}

	sort(all(C));
	for (int i = 0; i < M; i++)
		printf("%06d%06d\n", C[i][2], C[i][1]);
}

