#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int N, c_total;
	vector<vector<int>> vec(2, vector<int>(110));

	cin >> N;
	rep(j, 2)
	{
		rep(i, N)
		{
			cin >> vec.at(j).at(i);
		}
	}

	int max_val = 0;

	rep(i, N)
	{
		c_total = 0;
		for (int j = 0; j <= i; ++j)
		{
			c_total += vec.at(0).at(j);
		}
		for (int k = i; k < N; ++k)
		{
			c_total += vec.at(1).at(k);
		}

		max_val = max(max_val, c_total);
	}

	cout << max_val << endl;

	return 0;
}