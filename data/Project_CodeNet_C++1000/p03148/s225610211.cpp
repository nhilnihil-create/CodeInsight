#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
const int MOD = 1000000007;
#define MAX_N (100010)

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	map<int, priority_queue<int, vector<int>>> sushi;
	for (int i = 0; i < N; i++) {
		int t, d;
		scanf("%d%d", &t, &d);
		sushi[t].push(d);
	}

	vector<int> top, other;
	for (auto iter = sushi.begin(); iter != sushi.end(); iter++) {
		priority_queue<int, vector<int>> q = iter->second;
		top.push_back(q.top()); q.pop();
		while (!q.empty()) {
			other.push_back(q.top()); q.pop();
		}
	}
	sort(top.begin(), top.end(), greater<int>());
	sort(other.begin(), other.end(), greater<int>());

	ll res = 0;
	for (int k = 1; k <= K; k++) {
		if (k > (int)top.size() || K - k > (int)other.size())
			continue;

		ll local = 0;
		for (int i = 0; i < k; i++)
			local += (ll)top[i];
		for (int i = k; i < K; i++)
			local += (ll)other[i - k];
		local += (ll)k * (ll)k;

		res = max(res, local);
	}

	printf("%lld\n", res);

	return 0;
}
