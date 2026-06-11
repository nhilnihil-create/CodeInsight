#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> v;
	v.reserve(2*MAX);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.emplace_back(a, 1);
	}
	for (int i = 0; i < m; i++) {
		int b, c;
		cin >> b >> c;
		v.emplace_back(c, b);
	}
	sort(v.begin(), v.end(), greater<pair<int,int>>());
	long long ans = 0;
	for (auto e : v) {
		int val = e.first, num = e.second;
		if (n > num) {
			n -= num;
			ans += (long long) num * val;
		} else {
			ans += (long long) n * val;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}