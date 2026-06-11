#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
int n, del[N];
pii br[N], bl[N];
inline long long Solve1() {
	memset(del, 0, sizeof del);
	long long ans = 0;
	int np = 0, lp = n, rp = 1, flag = 1;
	while (flag) {
		flag = 0;
		while (lp && del[bl[lp].second]) --lp;
		if (lp && np < bl[lp].first) {
				ans += bl[lp].first - np;
				np = bl[lp].first;
				del[bl[lp].second] = 1;
				flag = 1;
		}
		while (rp <= n && del[br[rp].second]) ++rp;
		if (rp <= n && np > br[rp].first) {
				ans += np - br[rp].first;
				np = br[rp].first;
				del[br[rp].second] = 1;
				flag = 1;
		}
	}
	return ans + abs(np);
}
inline long long Solve2() {
	memset(del, 0, sizeof del);
	long long ans = 0;
	int np = 0, lp = n, rp = 1, flag = 1;
	while (flag) {
		flag = 0;
		while (rp <= n && del[br[rp].second]) ++rp;
		if (rp <= n && np > br[rp].first) {
				ans += np - br[rp].first;
				np = br[rp].first;
				del[br[rp].second] = 1;
				flag = 1;
		}
		while (lp && del[bl[lp].second]) --lp;
		if (lp && np < bl[lp].first) {
				ans += bl[lp].first - np;
				np = bl[lp].first;
				del[bl[lp].second] = 1;
				flag = 1;
		}
	}
	return ans + abs(np);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &bl[i].first, &br[i].first);
		bl[i].second  = br[i].second = i;
	}
	sort(bl + 1, bl + n + 1);
	sort(br + 1, br + n + 1);
	printf("%lld\n", max(Solve1(), Solve2()));
	return 0;
}