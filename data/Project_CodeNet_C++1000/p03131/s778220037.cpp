#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
	ll k, a, b;
	cin >> k >> a >> b;
	if (b - a < 2) {
		cout << 1 + k;
	}
	else {
		cout << max(0LL, (k - (a - 1)) / 2) * (b - a) + a + ((k - (a - 1)) % 2 ? 1 : 0);
	}
}