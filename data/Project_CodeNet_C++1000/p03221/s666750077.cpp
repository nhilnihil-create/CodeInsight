#include <bits/stdc++.h>
using namespace std;

bool compare_year(pair<long long, long long> left, pair<long long, long long> right)
{
	return left.second < right.second;
}

int main()
{
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	int N, M;
	scanf("%d %d", &N, &M);

	vector<long long> id(M);
	vector<vector<pair<long long, long long>>> ken(N, vector<pair<long long, long long>>()); // num year

	for (int i = 0; i < M; i++)
	{
		int P, Y;
		scanf("%d %d", &P, &Y);
		// cout << P << " " << Y << "\n";
		ken[P - 1].insert(ken[P - 1].end(), make_pair(i, Y));
	}
	// for (int i = 0; i < N; i++)
	// {
	// 	cout << i << "\n";
	// 	for (auto a : ken[i])
	// 	{
	// 		cout << a.first << " " << a.second << "\n";
	// 	}
	// }

	for (int i = 0; i < N; i++)
	{
		sort(ken[i].begin(), ken[i].end(), compare_year);
	}

	// cout << "=========\n";

	for (int i = 0; i < N; i++)
	{
		// cout << i << "\n";
		for (int j = 0; j < ken[i].size(); j++)
		{
			// cout << ken[i][j].first << " " << ken[i][j].second << "\n";
			id[ken[i][j].first] = (long long)(i + 1) * 1000000 + (long long)j + 1;
		}
	}

	for (int i = 0; i < M; i++)
	{
		printf("%012lld\n", id[i]);
	}

	return 0;
}