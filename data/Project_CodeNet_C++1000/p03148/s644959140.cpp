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

	pair<int, int> sushi[MAX_N];
	for (int i = 0; i < N; i++)
		scanf("%d%d", &sushi[i].second, &sushi[i].first);
	sort(sushi, sushi + N, greater<pair<int, int>>());

	map<int, int> sushi_type;
	ll min_delicious = 0;
	priority_queue<int, vector<int>, greater<int>> candidates;
	for (int i = 0; i < K; i++) {
		if (sushi_type.count(sushi[i].second) > 0) {
			candidates.push(sushi[i].first);
		}
		sushi_type[sushi[i].second]++;
		min_delicious += (ll)sushi[i].first;
	}

	ll min_type_num = sushi_type.size();
	min_delicious += min_type_num * min_type_num;

	priority_queue<int, vector<int>> additional_types;
	for (int i = K; i < N; i++) {
		if (sushi_type.count(sushi[i].second) == 0) {
			additional_types.push(sushi[i].first);
		}
		sushi_type[sushi[i].second]++;
	}

	ll res = min_delicious;
	ll prev = min_delicious;
	for (int k = min_type_num + 1; k <= K; k++) {
		if (candidates.size() < 1 || additional_types.size() < 1)
			break;

		ll local = prev;
		local -= (ll)candidates.top(); candidates.pop();
		local += (ll)additional_types.top(); additional_types.pop();

		local -= (ll)(k - 1) * (ll)(k - 1);
		local += (ll)k * (ll)k;

		res = max(res, local);
		prev = local;
	}

	printf("%lld\n", res);

	return 0;
}
