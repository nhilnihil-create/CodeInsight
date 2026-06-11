#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
int inp[100005];
vector<int> v;
 
int N;
int tree[200005];
const int BASE = 1e5 + 2;

void update(int i, int v) {
	i += BASE;
	while (i < 200005) {
		tree[i] += v;
		i += i & -i;
	}
}
 
int find(int i) {
	i += BASE;
	int ret = 0;
	while (i) {
		ret += tree[i];
		i -= i & -i;
	}
	return ret;
}
 
ll cal(int cur) {
	memset(tree, 0, sizeof tree);
	update(0, 1);
	int st = 0;
	ll ret = 0;
	for (int i = 1; i <= N; i++) {
		st += inp[i] <= cur ? 1 : -1;
		ret += find(st - 1);
		update(st, 1);
	}
	return ret;
}
 
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		inp[i] = x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= N; i++) {
		inp[i] = lower_bound(v.begin(), v.end(), inp[i]) - v.begin();
	}
	ll tot = (ll)N * (N + 1) / 2;
	ll target = tot / 2 + 1;
 
	int l = -1, r = v.size();
	while (l + 1 < r) {
		int mid = l + r >> 1;
		if (cal(mid) >= target) r = mid;
		else l = mid;
	}
	printf("%d", v[r]);
}