#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

void execute()
{
	int N, C;
	cin >> N >> C;

	vector<vector<int>> used(C, vector<int>(1000001, 0));
	for (int i = 0; i < N; i++)
	{
		int l, r, c;
		cin >> l >> r >> c;
		c--;
		used[c][l * 2]++;
		used[c][r * 2]--;
	}

	for (int i = 0; i < C; i++)
	{
		int current = 0;
		for (int j = 0; j < 1000000; j++)
		{
			if (used[i][j + 1] == 1)
			{
				current = 1;
			}
			if (used[i][j] == -1)
			{
				current = 0;
			}
			used[i][j] = current;
		}
	}

	int ans = 0;
	for (int i = 0; i < 1000000; i++)
	{
		int count = 0;
		for (int j = 0; j < C; j++)
		{
			count += used[j][i];
		}
		ans = max(ans, count);
	}
	cout << ans << endl;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}