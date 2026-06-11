#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int n, dex, A, B, a[N];

int f(int dex) {
	return min(abs(a[dex] - A), abs(a[dex] - B));
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	A = a[n - 1] >> 1, B = (a[n - 1] + 1) >> 1;
	for (int i = 1; i < n - 1; i++)
		if(f(i) < f(dex))
			dex = i;
	cout << a[n - 1] << ' ' << a[dex];
	return 0;
}