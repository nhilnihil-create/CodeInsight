#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto x : v) cerr << x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int i = 0; i < (n); ++i) cerr << a[i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> L(n), R(n), lefts(n), rights(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &L[i], &R[i]);
		lefts[i] = rights[i] = i;
	}
	sort(lefts.begin(), lefts.end(), [&](int a, int b) {
		return R[a] < R[b];
	});
	sort(rights.begin(), rights.end(), [&](int a, int b) {
		return L[a] > L[b];
	});
	auto f = [&](bool goingleft) {
		vector<bool> used(n);
		int x = 0, l = 0, r = 0;
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			if (goingleft) {
				while (used[lefts[l]]) ++l;
				int move = max(0, x - R[lefts[l]]);
				x -= move;
				ans += move;
				used[lefts[l]] = true;
			} else {
				while (used[rights[r]]) ++r;
				int move = max(0, L[rights[r]] - x);
				x += move;
				ans += move;
				used[rights[r]] = true;
			}
			goingleft = !goingleft;
		}
		ans += abs(x);
		return ans;
	};
	ll ans = max(f(true), f(false));
	printf("%lld\n", ans);
}
