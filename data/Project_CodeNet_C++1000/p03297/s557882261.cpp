#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long

int mgcd(int a, int b) {
	#ifdef LOCAL
	return gcd(a, b);
	#else 
	return __gcd(a, b);
	#endif
}

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (d < b) {
		cout << "No\n";
		return;
	}
	if (a < b) {
		cout << "No\n";
		return;
	}
	d %= b;
	if (c >= b) {
		cout << "Yes\n";
		return;
	}
	a %= b;
	int g = mgcd(d, b);
	int p = ((b - 1) / g) * g + a % g;
	while (p > b - 1) {
		p -= g;
	}
	if (abs(b - p) < b - c) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	
	int q;
	cin >> q;
	while (q--) {
		solve();
	}	
}
