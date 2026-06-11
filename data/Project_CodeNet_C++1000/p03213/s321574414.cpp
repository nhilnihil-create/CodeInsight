#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define LIMIT(d_in, d_min, d_max) max(d_min, min(d_max, d_in))
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

vector<pair<int, int>> Factorization(int N)
{
	vector<pair<int, int>> factorization;

	int rest_N = N;
	for (int j = 2; j <= (int)sqrt(N); j++)
	{
		if (rest_N % j == 0)
		{
			int tmp = 0;
			for (; rest_N % j == 0;)
			{
				rest_N /= j;
				tmp++;
			}
			factorization.push_back(make_pair(j, tmp));
		}
		if (rest_N == 1)
			return factorization;
	}
	factorization.push_back(make_pair(rest_N, 1));

	return factorization;
}

void execute()
{
	int N;
	cin >> N;
	vector<int> prime(N + 1, 0);
	int count_3 = 0;
	int count_5 = 0;
	int count_15 = 0;
	int count_25 = 0;
	int count_75 = 0;

	for (int i = 2; i <= N; i++)
	{
		vector<pair<int, int>> fac = Factorization(i);

		for (int j = 0; j < fac.size(); j++)
		{
			prime[fac[j].first] += fac[j].second;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if ((3 - 1) <= prime[i])
			count_3++;
		if ((5 - 1) <= prime[i])
			count_5++;
		if ((15 - 1) <= prime[i])
			count_15++;
		if ((25 - 1) <= prime[i])
			count_25++;
		if ((75 - 1) <= prime[i])
			count_75++;
	}

	/*
	cout << count_3 << endl;
	cout << count_5 << endl;
	cout << count_15 << endl;
	cout << count_25 << endl;
	cout << count_75 << endl;
	*/

	int ans = 0;
	ans += count_5 * (count_5 - 1) * (count_3 - 2) / 2;
	ans += count_25 * (count_3 - 1);
	ans += count_15 * (count_5 - 1);
	ans += count_75;
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