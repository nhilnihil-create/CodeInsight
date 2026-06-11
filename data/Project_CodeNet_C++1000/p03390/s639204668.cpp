#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;

int main() {
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		ll A, B;
		cin >> A >> B;
		if (A > B) swap(A, B);
		if (A == B) {
			cout << 2 * A - 2 << endl;
			continue;
		}
		ll l = 0, r = 1e10;
		while ((r - l) > 1) {
			ll m = (l + r) / 2;
			bool ok = 1;
			for (int i = -10; i <= 10; i++) {
				ll a = (m + 1) / 2 + i;
				ll b = (m / 2) + 1 - i;
				if (a <= 0 || a > m || b <= 0 || b > m) continue;
				if (a >= A) a++;
				if (b >= B) b++;
				if (a*b >= A * B) {
					ok = 0;
					break;
				}
			}
			if (ok) l = m;
			else r = m;
		}
		cout << l << endl;
	}
}
