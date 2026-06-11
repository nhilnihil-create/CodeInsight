#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	
	int ans = p[n - 1] / 2;
	for (int i = 0; i < n - 1; i++) {
		ans += p[i];
	}

	cout << ans << endl;
	return 0;
}