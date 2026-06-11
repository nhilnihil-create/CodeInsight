#include <bits/stdc++.h>

using namespace std;

int n, cnt[100005];
long long d[100005];
pair<long long, int> p[100005];
vector<int> to[100005];
int ta;
long long tb;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &p[i].first);
		p[i].second = i + 1;
		cnt[i] = 1;
	}
	sort(p, p + n);
	for (int i = n - 1; i; i--) {
		tb = p[i].first - n + 2 * cnt[i];
		ta = lower_bound(p, p + i, make_pair(tb, 0)) - p;
		if (p[ta].first != tb) {
			printf("-1\n");
			return 0;
		}
		d[ta] += d[i] + cnt[i];
		to[ta].push_back(i);
		cnt[ta] += cnt[i];
	}
	if (d[0] != p[0].first) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
		for (int j : to[i])
			printf("%d %d\n", p[i].second, p[j].second);
	return 0;
}