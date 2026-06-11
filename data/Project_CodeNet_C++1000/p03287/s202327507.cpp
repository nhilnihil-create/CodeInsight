#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "rfd_wrap.h"
#endif

typedef long long ll;
typedef pair<int, int> pii;

#define bt(x) (1LL << (x))
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int inf = 0x3f3f3f3f;
const ll INF = 2e18;

int main() {
	FastIO;

	int n, m;
	cin >> n >> m;

	vector<int> a(n), c(n + 1, 0);
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		c[i + 1] = (c[i] + a[i]) % m;
	}

	map<int, int> cnt;
	for(int i=0; i<=n; ++i) cnt[c[i]]++;

	ll res = 0;
	for(auto& qq : cnt) {
		res += 1LL * qq.second * (qq.second - 1) / 2;
	}

	cout << res << "\n";

	return 0;
}