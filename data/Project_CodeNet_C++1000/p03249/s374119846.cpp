#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, int> pli;
typedef pair <int, int> pii;

long long d[100010];
map <long long, int> all;
long long dp[100010], size[100010];

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%lld", &d[i]);
		all[d[i]] = i;
	}
	vector <pii> ans;
	int pos = all.begin()->se;
	for (auto it = all.rbegin(); it != all.rend(); it++){
		long long x = it->fi; int id = it->se;
		if (id == pos) continue;
		size[id]++;
		long long need = d[id] + 2 * size[id] - n;
		if (!all.count(need) || need >= x){
			printf("-1\n");
			return 0;
		}
		int fa = all[need];
		ans.push_back(mp(fa, id));
		size[fa] += size[id], dp[fa] += dp[id] + size[id];
	}
	if (dp[pos] != d[pos]){
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < ans.size(); i++){
		printf("%d %d\n", ans[i].fi + 1, ans[i].se + 1);
	}
	return 0;
}
