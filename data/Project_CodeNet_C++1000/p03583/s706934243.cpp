
// C - 4/N

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll N;
	cin >> N;

	for (ll h=1; h<=3500; h++) {
		for (ll n=h; n<=3500; n++) {
			if (4*h*n - N*n - N*h <= 0) continue;

			if (N*h*n % (4*h*n - N*n - N*h) == 0) {
				ll w = N*h*n / (4*h*n - N*n - N*h);
				cout << h << " " << n << " " << w << endl;
				return 0;
			}
		}
	}

	return 0;
}