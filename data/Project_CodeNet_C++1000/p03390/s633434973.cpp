#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
 
int f(int a, int b) {
	if (a > b) swap(a, b);
	if (a == b) return 2 * a - 2;
	int x = 2 * sqrt((long double)a * b - 0.5) - 2;
	int st = 1, ed = 2000000000, mid;	//oooxxx, [st, ed)
	while (ed - st >= 2) {
		mid = (st + ed) / 2;
		if ((a * b - 1) / mid >= b) st = mid;
		else ed = mid;
	}
	if ((a * b - 1) / st == b) x--;
	return x;
}
 
signed main() {
	int q, a, b;
	cin >> q;
	while (q--) { cin >> a >> b; cout << f(a, b) << endl; }
	return 0;
}