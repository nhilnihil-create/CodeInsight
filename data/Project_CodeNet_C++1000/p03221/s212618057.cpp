#include <iostream>
#include <iomanip>
#include <cassert>

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

using CC = pair<int, int>;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> P(M);
	vector<int> Y(M);

	vector<vector<int>> S(N, vector<int>());
	rep(i, M)
	{
		cin >> P[i] >> Y[i];
		S[P[i]-1].push_back(Y[i]);
	}

	vector<unordered_map<int, int>> T(N);
	rep(i, N)
	{
		sort(S[i].begin(), S[i].end());

		rep(j, S[i].size())
		{
			T[i][S[i][j]] = j+1;
		}
	}

	rep(i, M)
	{
		string A, B;
		A = to_string(P[i]);
		A = string(6 - A.size(), '0') + A;

		B = to_string(T[P[i]-1][Y[i]]);
		B = string(6 - B.size(), '0') + B;

		cout << A + B << endl;
	}
	
	return 0;
}