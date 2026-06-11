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

	vector<vector<lint>> cost(C, vector<lint>(C));
	vector<vector<lint>> count(3, vector<lint>(C));
	vector<vector<lint>> cal(3, vector<lint>(C, 0));

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> cost[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			lint tmp;
			cin >> tmp;
			count[(i + j) % 3][tmp - 1]++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < C; j++)
		{
			for (int k = 0; k < C; k++)
			{
				cal[i][k] += count[i][j] * cost[j][k];
			}
		}
	}

	lint ans = INF64;
	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (i == j)
				continue;

			for (int k = 0; k < C; k++)
			{
				if (i == k)
					continue;
				if (j == k)
					continue;

				ans = min(ans, cal[0][i] + cal[1][j] + cal[2][k]);
			}
		}
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