#include<bits/stdc++.h>
using namespace std;

int f(int x, int y) {
	if(y == 0) return x;
	else return f(y, x % y);
}

int main() {
	int n, x; cin >> n >> x;
	int d[n];
	for (int i = 0; i < n; i++)
	{
		int s; cin >> s;
		d[i] = abs(s - x);
	}

	int res = d[0];
	for (int i = 1; i < n; i++)
	{
		res = f(res, d[i]);
	}

	cout << res << endl;
	return 0;
}
