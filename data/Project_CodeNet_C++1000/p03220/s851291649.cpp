#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, t, a; cin >> n >> t >> a;
	int h[n];
	for(int i = 0; i < n; i++) cin >> h[i];

	double tmp = 1e9;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if(tmp > abs(t - 0.006 * h[i] - a)) {
			tmp = abs(t - 0.006 * h[i] - a);
			res = i;
		}
	}
	cout << res + 1 << endl;
	return 0;
}
