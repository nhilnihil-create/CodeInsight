#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100000;

vector<int>G[MAXN + 5];
map<ll, int>mp;
int siz[MAXN + 5];

ll check(int x) {
	ll ret = 0;
	for (int i = 0; i < G[x].size(); i++) {
		int to = G[x][i];
		ret += check(to) + siz[to];
	}
	return ret;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ll D; scanf("%lld", &D);
		mp[D] = i, siz[i] = 1;
	}
	map<ll, int>::reverse_iterator rt;
	for (map<ll, int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++) {
		if (siz[it->second] == n) {
			rt = it;
			break;
		}
		int x = it->second;
		ll k = it->first + siz[x] - (n - siz[x]);
		if (k < it->first && mp.count(k)) {
			int p = mp[k];
			siz[p] += siz[x];
			G[p].push_back(x);
		}
		else {
			puts("-1");
			return 0;
		}
	}
	if (check(rt->second) == rt->first) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < G[i].size(); j++)
				printf("%d %d\n", i, G[i][j]);
		}
	}
	else puts("-1");

	return 0;
}
