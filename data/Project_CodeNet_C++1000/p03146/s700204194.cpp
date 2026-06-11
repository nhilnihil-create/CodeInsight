#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int s;
	cin >> s;

	vector<int> v = { s };
	int ans = 0;

	while (1) {
		int n, p;
		p = v.at(v.size() - 1);
		if (p % 2) n = 3 * p + 1;
		else n = p / 2;
		if (count(v.begin(), v.end(), n)) {
			ans = v.size() + 1;
			break;
		}
		else {
			v.push_back(n);
		}
	}

	cout << ans << endl;
}