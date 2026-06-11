#include <bits/stdc++.h>
using namespace std;

#define d first
#define t second

const long long inf = 100000000000000037;
const int maxn = 100005;

int n, k;
long long s, x, ans = -inf;
pair < int, int > lose;
pair < int, int > sushi[maxn];
multiset < pair < int, int > > cands;
map < int, multiset < int > > cnt;

bool cmp (pair < int, int > a, pair < int, int > b) {
	return a.d > b.d;
}

signed main () {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &sushi[i].t, &sushi[i].d);
	sort(sushi, sushi + n, cmp);
	for (int i = 0; i < k; ++i) {
		cnt[sushi[i].t].insert(sushi[i].d);
		s += sushi[i].d, x = cnt.size();
		ans = max(ans, s + x * x);
	}
	for (int i = 0; i < k; ++i) {
		if (int(cnt[sushi[i].t].size()) >= 2)
			cands.insert(sushi[i]);
	}
	for (int i = k; i < n && !cands.empty(); ++i) {
		if (cnt.find(sushi[i].t) == cnt.end()) {
			cnt[sushi[i].t].insert(sushi[i].d);
			lose = *cands.begin();
			s += sushi[i].d - lose.d, ++x;
			if (int(cnt[lose.t].size()) == 2) {
				for (auto taste: cnt[lose.t])
					cands.erase(make_pair(taste, lose.t));
				cnt[lose.t].clear();
			}
			else {
				cands.erase(cands.begin());
				cnt[lose.t].erase(cnt[lose.t].find(lose.d));
			}
			ans = max(ans, s + x * x);
		}
	}
	printf("%lld\n", ans);
}
