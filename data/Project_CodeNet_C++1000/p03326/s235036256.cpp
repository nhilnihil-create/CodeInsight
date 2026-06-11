#include <bits/stdc++.h>
using namespace std;

const int nm = 1e3;
int n, m;
long long x, v[8][nm], sum, ans = -3e13;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++) {
			cin >> x;
			for (int k = 0; k < 8; k++)
				v[k][i] += 1 << j & k ? x : -x;
		}
	for (int i = 0; i < 8; i++) {
		sort(v[i], v[i] + n, greater<long long>());
		sum = 0;
		for (int j = 0; j < m; j++)
			sum += v[i][j];
		ans = max(ans, sum);
	}
	cout << ans << endl;
}
