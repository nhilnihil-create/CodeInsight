#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, c;
	cin >> n >> c;
	bool d[c][100000];
	fill(d[0], d[0]+c*100000, false);
	for (int i = 0; i < n; i++) {
		int s, t, ch;
		cin >> s >> t >> ch;
		for (int i = s; i <= t; i++) {
			d[ch-1][i-1] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < 100000; i++) {
		int count = 0;
		for (int ch = 0; ch < c; ch++) {
			if (d[ch][i])
				count++;
		}
		ans = max(ans, count);
	}
	cout << ans << endl;
	return 0;
}