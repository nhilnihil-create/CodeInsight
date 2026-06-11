#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dist(ll a, ll b, ll c) {
	ll ret = (a - b) * (a - b);
	ret += c;
	return ret;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	int d[n][3];
	for (int i = 0; i < n; i++)
	{
		if (i == 0) {d[i][0] = a[i]; d[i][1] = b[i]; d[i][2] = c[i];}
		else
		{
			d[i][0] = max(d[i - 1][1], d[i - 1][2]) + a[i];
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + b[i];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + c[i];
		}
	}
	int m = max(d[n - 1][0], max(d[n - 1][1], d[n - 1][2]));
	cout << m << endl;
	return 0;
}
