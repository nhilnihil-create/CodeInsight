#include <iostream>
using namespace std;

int main () {
	ios::sync_with_stdio (false); cin.tie (0);

	int n; cin >> n;
	long long f[n + 1][3] = {0};
	for (int i = 1; i <= n; i++) cin >> f[i][0] >> f[i][1] >> f[i][2];
	
	for (int i = 1; i <= n; i++) {
		f[i][0] += max (f[i - 1][1], f[i - 1][2]);
		f[i][1] += max (f[i - 1][0], f[i - 1][2]);
		f[i][2] += max (f[i - 1][0], f[i - 1][1]);
	}

	cout << max (f[n][0], max (f[n][1], f[n][2]));
	return 0;
}