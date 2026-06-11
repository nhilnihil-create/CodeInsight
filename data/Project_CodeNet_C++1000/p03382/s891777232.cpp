#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;

int n, mx, mx2, mi, a[N];
int main()
{
	int i, t;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	for (i = 0; i < n; i++) {
		if (a[i] > mx - a[i]) t = mx - a[i];
		else t = a[i];
		if (t > mx2) mx2 = t, mi = a[i];
	}
	cout << mx << ' ' << mi;
    return 0;
}