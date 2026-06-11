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
	int N, M;
	cin >> N >> M;

	vector<vector<lint>> data(8, vector<lint>(N, 0));

	for (int i = 0; i < N; i++)
	{
		lint a, b, c;
		cin >> a >> b >> c;
		for (int j = 0; j < (1 << 3); j++)
		{
			data[j][i] += (j & (1 << 0)) ? a : -a;
			data[j][i] += (j & (1 << 1)) ? b : -b;
			data[j][i] += (j & (1 << 2)) ? c : -c;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		sort(all(data[i]), greater<lint>());
	}

	lint ans = -INF64;
	for (int i = 0; i < 8; i++)
	{

		lint value = 0;
		for (int j = 0; j < M; j++)
		{
			value += data[i][j];
		}
		ans = max(ans, value);
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