#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int x[n], c[n];
	for(int i = 0; i < n; i++) {
		cin >> x[i];
		c[i] = x[i];
	}
	sort(c, c + n);
	for (int i = 0; i < n; i++)
	{
		int p = lower_bound(c, c + n, x[i]) - c;
		if(p < n / 2) cout << c[n/2] << endl;
		else cout << c[n/2-1] << endl;
	}

	return 0;
}
