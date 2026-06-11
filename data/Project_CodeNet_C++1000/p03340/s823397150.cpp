#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <bitset>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// for (int i = 0; i < n; i++) {
	// 	bitset<10> b(a[i]);
	// 	printf("%2d: %4d, %s\n", i, a[i], b.to_string().c_str());
	// }

	long long ans = 0;
	int l = 0, r = 1;
	int stat = 0;
	while (r <= n) {

// printf("l %2d, r %2d: ", l, r);

		if ((stat & a[r-1]) == 0) {
			stat ^= a[r-1];
			ans += r - l;
// printf(" r++: add %d, ans %d\n", r - l, ans);
			r++;
			continue;
		}

// printf(" l++: \n");
		stat ^= a[l];
		l++;
	}

	cout << ans << endl;
	return 0;
}
