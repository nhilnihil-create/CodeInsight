#include <iostream>
#include <algorithm>
using namespace std;
using i64 = int64_t;

int main() {
	i64 x, y; cin >> x >> y;
	if (x % y == 0) cout << -1;
	else cout << x;
	return 0;
}