#include <cstdio>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

pii inp[100005];
int siz[100005];
ll dp[100005];
vector<pii> ans;

int main() {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		ll x; scanf("%lld", &x);
		inp[i] = {x, i};
		siz[i] = 1;
	}
	sort(inp + 1, inp + N + 1);
	for (int i = N; i >= 2; i--) {
		ll cur; int id;
		tie(cur, id) = inp[i];
		int del = N - 2 * siz[id];
		auto it = *lower_bound(inp + 1, inp + i, pii(cur - del, 0));
		if (it.first != cur - del || del <= 0) return !printf("-1");
		siz[it.second] += siz[id];
		dp[it.second] += dp[id] + siz[id];
		if (id > it.second) swap(id, it.second);
		ans.push_back({id, it.second});
	}
	if (dp[inp[1].second] != inp[1].first) return !printf("-1");
	sort(ans.begin(), ans.end());

	for (pii &x : ans) {
		printf("%lld %d\n", x.first, x.second);
	}
}