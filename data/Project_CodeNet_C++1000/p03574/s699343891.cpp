#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
	int h, w;
	cin >> h >> w;

	vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
	vector<int> dy = {-1, -1, 0, 1, 1, 1, 0, -1};

	vector<string> mass(h);
	rep(i, h) cin >> mass[i];

	rep(i, h)
	{
		rep(j, w)
		{
			int cnt = 0;
			rep(k, 8)
			{
				int y = i + dy[k], x = j + dx[k];
				if (0 <= x && x < w && 0 <= y && y < h && mass[y][x] == '#')
				{
					cnt++;
				}
			}
			if (mass[i][j] == '.')
			{
				cout << cnt;
			}
			else
			{
				cout << '#';
			}
		}
		cout << '\n';
	}
	cout << '\n';
	return 0;
}
