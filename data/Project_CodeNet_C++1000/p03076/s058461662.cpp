#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> a(5);
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	vector<int> p = { 0, 1, 2, 3, 4 };
	int final_answer = INT_MAX;
	do {
		int ans = 0;
		for (int i = 0; i < 5; i++) {
			while (ans % 10 != 0) {
				ans += 1;
			}
			ans += a[p[i]];
		}
		final_answer = min(final_answer, ans);
	} while (next_permutation(p.begin(), p.end()));
	cout << final_answer << '\n';
	
	return 0;
}
