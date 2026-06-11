# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <tuple>
# include <unordered_map>
# include <numeric>
# include <complex>
# include <bitset>
# include <random>
# include <chrono>
# include <cstdlib>
# include <tuple>
# include <array>
# include <climits>
#define ll long long int
#define rep(i,rept) for (ll i = 0; i < rept; i++)
using namespace std;
int ketawa(ll num) {
	int dig, sum = 0;
	while (num) {
		dig = num % 10;
		sum = sum + dig;
		num = num / 10;
	}
	return sum;
}
ll solve(int n, int k)
{
	int memo[110000];
	fill(memo, memo + k, INT_MAX);
	deque<ll> q;
	q.emplace_front(n);
	memo[n] = 0;

	while (!q.empty()) {
		ll cur = q.front(); q.pop_front();
		if (cur%k == 0) {
			return memo[cur] + 1;
		}
		//
		ll next = cur * 10;
		if (memo[next%k] > memo[cur]) {
			q.push_front(next%k);
			memo[next%k] = memo[cur];
		}

		//
		next = cur + 1;

		if (memo[next%k] > memo[cur]+1) {
			q.push_back(next%k);
			memo[next%k] = memo[cur] + 1;
		}
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	cout << solve(1, n);
	return 0;
}
