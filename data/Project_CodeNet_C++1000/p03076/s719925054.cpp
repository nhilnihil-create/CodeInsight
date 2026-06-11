// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v(5);
	
	for(int i = 0; i < 5; i++) cin >> v[i];

	auto solve = [](vector<int> v) {
		int t = 0;
		for(int i = 0; i < v.size(); i++) {
			if(t % 10 != 0) {
				t += 10 - t % 10;
			}
			t += v[i];
		}
		return t;
	};

	int ans = 1e9;

	do {
		ans = min(ans, solve(v));
	} while(next_permutation(v.begin(), v.end()));
	
	cout << ans;

	return 0;
}
