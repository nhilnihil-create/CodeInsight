#include <iostream>
#include <cstdio>
using namespace std;

int n, mx, m, x, i, j, t, a[100005];
int main()
{
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	for (i = 0; i < n; i++) {
		t = min(a[i], mx - a[i]);
		if (t > m) {
			m = t;
			x = a[i];
		}
	}
	cout << mx << " " << x;
    return 0;
}
