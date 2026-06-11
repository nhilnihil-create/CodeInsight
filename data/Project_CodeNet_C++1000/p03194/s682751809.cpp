#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double EPS = 1e-10;

int main() {
	ll N, P;
	cin >> N >> P;
	ll i = 2;
	ll ans = 1;
	while (i*i <= P) {
		if (P%i) {
			i++;
			continue;
		}
		int k = 0;
		while (P%i == 0) {
			k++;
			P /= i;
		}
		for (int j = 0; j < k / N; j++) ans *= i;
	}
	if (P > 0 && N == 1) {
		ans *= P;
	}
	cout << ans << endl;
}