#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MN = 1e6+5;

ii A[MN];
inline ii merge(ii a, ii b) {
	if (a.f < b.f) swap(a, b);
	return ii(a.f, max(a.s, b.f));
}

int main() {
	if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < (1<<N); ++i) {
		cin >> A[i].f;
		A[i].s = -1e9;
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < (1<<N); ++j)
			if (j>>i&1) A[j] = merge(A[j], A[j^(1<<i)]);
	int ans = A[0].f+A[0].s;
	for (int i = 1; i < (1<<N); ++i) {
		ans = max(A[i].f+A[i].s, ans);
		cout << ans << '\n';
	}
}
