#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, x; cin >> n >> x;
	vector<int>m(n); for (auto&& i : m)cin >> i;

	int ans = 0;
	for (int i = 0; i < m.size(); i++) {
		x -= m[i]; ans++;
	}
	sort(m.begin(), m.end());
	ans += (x / m[0]);
	cout << ans << endl;

	return 0;
}