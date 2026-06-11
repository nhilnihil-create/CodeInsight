#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN], n, mx, num;

int dis(int r) {
	return min(abs(r - (mx + 1) / 2), abs(r - mx / 2));
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], mx = max(mx, a[i]);
	num = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != mx && dis(num) >= dis(a[i]))
			num = a[i];
	cout << mx << ' ' << num;
}