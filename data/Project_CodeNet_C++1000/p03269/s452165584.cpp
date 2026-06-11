#include <bits/stdc++.h>
using namespace std;

int main() {
	int l; cin >> l;
	int sum = 0, n;
	vector<tuple<int, int, int>> ans;
	for(int i = 0; sum + (1 << i) < l; ++i) {
		ans.emplace_back(i + 1, i + 2, 0);
		ans.emplace_back(i + 1, i + 2, (1 << i));
		n = i + 2;
		sum += (1 << i);
	}
	for(int i = n - 2; i >= 0; --i) {
		if(sum + (1 << i) < l) {
			ans.emplace_back(i + 1, n, sum + 1);
			sum += (1 << i);
		}
	}
	cout << n << " " << ans.size() << '\n';
	for(auto e : ans) {
		int a, b, c;
		tie(a, b, c) = e;
		printf("%d %d %d\n", a, b, c);
	}
	return 0;
}