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

	map<int, vector<int>> sushi;
	for (int i = 0; i < N; i++) {
		int t, d;
		scanf("%d%d", &t, &d);
		sushi[t].push_back(d);
	}

	vector<int> top, other;
	for (auto iter = sushi.begin(); iter != sushi.end(); iter++) {
		vector<int> elements = iter->second;
		sort(elements.begin(), elements.end(), greater<int>());
		top.push_back(elements[0]);
		for (int i = 1; i < (int)elements.size(); i++)
			other.push_back(elements[i]);
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
