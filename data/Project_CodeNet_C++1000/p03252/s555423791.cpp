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
	string S, T;
	cin >> S >> T;

	vector<vector<int>> X(26, vector<int>());
	for (int i = 0; S[i]; i++)
	{
		int idx = S[i] - 'a';
		X[idx].push_back(i);
	}

	vector<vector<int>> Y(26, vector<int>());
	for (int i = 0; T[i]; i++)
	{
		int idx = T[i] - 'a';
		Y[idx].push_back(i);
	}

	bool ans = true;
	for (int i = 0; i < 26; i++)
	{
		if (X[i].size() == 0)
			continue ;
		int c = X[i][0];
		int i_y = T[c] - 'a';
		if (X[i].size() != Y[i_y].size())
		{
			ans = false;
			break ;
		}
		for (int j = 0; j < (int)X[i].size(); j++)
		{
			if (X[i][j] != Y[i_y][j])
				ans = false ;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}

