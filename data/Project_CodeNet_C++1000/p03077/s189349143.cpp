#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	ll n;
	cin >> n;
	ll a[5];
	rep(i, 5) cin >> a[i];
	sort(a, a + 5);
	cout << 4 + (n + a[0]-1) / a[0] << endl;
	return 0;
}
