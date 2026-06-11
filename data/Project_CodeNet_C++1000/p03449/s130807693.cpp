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
	vector<vector<int>> su(2, vector<int>(110));


	cin >> N;
	rep(j, 2)
	{
		rep(i, N)
		{
			cin >> vec.at(j).at(i);
			if (i == 0) {
				su.at(j).at(i) = 0;
			}
			su.at(j).at(i + 1) = su.at(j).at(i) + vec.at(j).at(i);
		}
	}

	int max_val = 0;

	rep(i, N)
	{
		c_total = (su.at(0).at(i + 1) - su.at(0).at(0)) + (su.at(1).at(N) - su.at(1).at(i));
		max_val = max(max_val, c_total);
	}

	cout << max_val << endl;

	return 0;
}