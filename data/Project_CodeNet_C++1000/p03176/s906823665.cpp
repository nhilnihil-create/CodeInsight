#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200005
#define mod 1000000007

ll bit[N], n, h[N], a[N];
void insert(ll val, int idx) {
	for (int i = idx; i < N; i += (i & -i)) {
		bit[i] = max(val, bit[i]);
	}
}

ll query(int idx) {
	ll ans = 0;
	for (int i = idx; i > 0; i -= (i & -i)) {
		ans = max(bit[i], ans);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memset(bit, 0, sizeof bit);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll q = query(h[i]);
		if (q + a[i] > ans) {
			ans = q + a[i];
		}
		insert(q + a[i], h[i]);
		//ll tmp = query(h[i]);
		//cout << tmp << "\n";
		//ans = max(ans, query(h[i]));
	}

	cout << ans;
}