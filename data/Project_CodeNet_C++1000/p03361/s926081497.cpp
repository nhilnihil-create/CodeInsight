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
	int h, w;
	cin >> h >> w;

	char T[h][w];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> T[i][j];
	
	bool ans = true;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (T[i][j] == '.')
				continue ;

			bool flag = false;
			if (i != 0)	
				(T[i-1][j] == '#') ? (flag = true) : 0;
			if (i != h-1)
				(T[i+1][j] == '#') ? (flag = true) : 0;
			if (j != 0)
				(T[i][j-1] == '#') ? (flag = true) : 0;
			if (j != w-1)
				(T[i][j+1] == '#') ? (flag = true) : 0;
			if (!flag)
				ans = false;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}

