#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
	int n, k;
	cin >> n >> k;

	if (k % 2 == 1) {
		ll l = n / k;
		cout << l * l * l << endl;
	}
	else {
		ll l = n / k;
		ll ans = l * l * l;
		l = n / (k / 2) - l;
		ans += l * l * l;
		cout << ans << endl;
	}

}