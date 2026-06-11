#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n, q;
char c[N];
char a[N], b[N];
int dl, dr;

int die(int x) {
	for (int i = 1; i <= q; i++) {
		if (a[i] != c[x])
			continue;
		if (b[i] == 'R')
			x++;
		else
			x--;
		if (x == 0)
			return -1;
		if (x == n + 1)
			return 1;
	}
	return 0;
}

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= q; i++)
		cin >> a[i] >> b[i];
	int l = 0, r = n + 1, md;
	while (r - l > 1) {
		md = (r + l) / 2;
		if (die(md) == -1)
			l = md;
		else
			r = md;
	}
	dl = l;
	l = 0, r = n + 1, md;
	while (r - l > 1) {
		md = (r + l) / 2;
		if (die(md) == 1)
			r = md;
		else
			l = md;
	}	
	dr = r;
	if (dr <= dl)
		dr = dl + 1;
	cout << n - dl - (n - (dr) + 1);
	return 0;
}



























