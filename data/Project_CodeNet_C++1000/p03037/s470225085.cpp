#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;	
	vector<int> l(m), r(m);
	vector<int> num(n + 5, 0);
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		num[l[i]]++;
		num[r[i] + 1]--;
	}
	int ans = 0;
	for (int i = 1; i < n + 5; i++) {
		num[i] += num[i - 1];
		if (num[i] == m) ans++;
	}
	cout << ans << endl;
	return 0;
}