// abc110_a.cc
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> a(3);
	for (auto& i : a)
		cin >> i;
	sort(a.rbegin(), a.rend());

	int ans = a[0] * 10;
	ans += a[1];
	ans += a[2];

	cout << ans << "\n";

}