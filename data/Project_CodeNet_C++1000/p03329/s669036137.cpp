#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int d[n+1];
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = d[i-1]+1;
		int tmp = 1;
		for (int j = 1; j <= 6; j++) {
			tmp *= 6;
			if ((i-tmp) >= 0) {
				d[i] = min(d[i], d[i-tmp]+1);
			}
		}
		tmp = 1;
		for (int j = 1; j <= 5; j++) {
			tmp *= 9;
			if ((i-tmp) >= 0) {
				d[i] = min(d[i], d[i-tmp]+1);
			}
		}
	}
	cout << d[n] << endl;
	return 0;
}