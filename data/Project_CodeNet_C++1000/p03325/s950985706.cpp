#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ll a;
		cin >> a;
		while (a % 2 == 0) {
			ans++;
			a /= 2;
		}
	}

	cout << ans << endl;
	return 0;
}
