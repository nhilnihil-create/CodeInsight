#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int x[n+1], y[n+1], t[n+1];
	x[0] = y[0] = t[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> x[i] >> y[i];
	}
	bool ok = true;
	for (int i = 1; i <= n; i++)
	{
		if((t[i] - t[i-1]) < abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]) || (t[i] - t[i-1]) % 2 != (abs(x[i] - x[i-1]) + abs(y[i] - y[i-1])) % 2) {
			ok = false;
			break;
		}
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
