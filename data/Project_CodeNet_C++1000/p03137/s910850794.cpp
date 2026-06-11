#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	int m; cin >> m;
	long long x[m];
	for(int i = 0; i < m; i++) cin >> x[i];
	sort(x, x + m);
	long long d[m-1];
	for (int i = 0; i < m-1; i++)
	{
		d[i] = x[i+1] - x[i];
	}
	sort(d, d + m - 1);
	long long sum = 0;
	for (int i = 0; i < max(m - n, 0); i++)
	{
		sum += d[i];
	}

	cout << sum << endl;
	return 0;
}
