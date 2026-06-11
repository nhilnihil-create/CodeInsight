#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, c;
	cin >> n >> c;
	int d[c][c];
	for (int i = 0; i < c; i++)
		for (int j = 0; j < c; j++)
			cin >> d[i][j];
	map<int, int> m0;
	map<int, int> m1;
	map<int, int> m2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int col;
			cin >> col;
			if ((i+1+j+1)%3 == 0) {
				m0[col]++;
			} else if ((i+1+j+1)%3 == 1) {
				m1[col]++;
			} else {
				m2[col]++;
			}
		}
	}

	long long ans = -1;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			if (i == j)
				continue;
			for (int k = 0; k < c; k++) {
				if (i == k || j == k)
					continue;
				long long count = 0;
				for (auto e : m0) {
					count += (long long)(d[e.first-1][i])*(long long)(e.second);
				}
				for (auto e : m1) {
					count += (long long)(d[e.first-1][j])*(long long)(e.second);
				}
				for (auto e : m2) {
					count += (long long)(d[e.first-1][k])*(long long)(e.second);
				}
				if (ans == -1)
					ans = count;
				else
					ans = min(ans, count);
			}
		}
	}
	cout << ans << endl;
	return 0;
}