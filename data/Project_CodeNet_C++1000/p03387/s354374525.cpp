#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	const int p = 3;
	vector<int> c(p);
	cin >> c[0] >> c[1] >> c[2];
	sort(c.rbegin(), c.rend());
	int diff = c[0] - c[1] + c[0] - c[2];
	int ans = 0;
	if (diff % 2 == 0) {
		ans = diff / 2;
	}
	else {
		c[0]++;
		diff = c[0] - c[1] + c[0] - c[2];
		ans = diff / 2 + 1;
	}
	cout << ans << endl;
    return 0;
}