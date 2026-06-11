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
#include <numeric>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> x(N);
	rep(i, N)
	{
		cin >> x[i];
	}

	int ans = numeric_limits<int>::max();
	for (int i = 0; i + K - 1 < N; ++i)
	{
		int cand = min(abs(x[i]), abs(x[i+K-1])) + (x[i+K-1] - x[i]);
		ans = min(ans, cand);
	}

	cout << ans << endl;
}