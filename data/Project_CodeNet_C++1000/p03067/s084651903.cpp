#include <bits/stdc++.h>
#define Int int64_t

using namespace std;
using P = pair<int, int>;

int main() {
	vector<P> v(3);
	for (int i = 0; i < 3; ++i) {
		int a;
		cin >> a;
		v[i] = P(a, i + 1);
	}
	sort(v.begin(), v.end());

	if (v[1].second == 3) { cout << "Yes" << endl; }
	else { cout << "No" << endl; }

	return 0;
}
