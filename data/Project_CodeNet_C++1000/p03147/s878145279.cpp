#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	int ans = 0;
	rep(i, 100) {
		rep(j, n) {
			if (h[j] == 0) continue;
			while (h[j] > 0) {
				h[j]--;
				j++;
			}
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}