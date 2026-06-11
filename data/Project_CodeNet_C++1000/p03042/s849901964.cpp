#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
	int x = 0, fh = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') fh = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return x * fh;
}
string s;
int f1, f2, i, a[4];
int main() {
	cin >> s;
	for (i = 0; i < 4; i++) a[i] = s[i] - 48;
	if (a[2] * 10 + a[3] <= 12 && a[2] + a[3] != 0) f1 = 1;
	if (a[0] * 10 + a[1] <= 12 && a[0] + a[1] != 0) f2 = 1;
	if (f1 && !f2) cout << "YYMM\n";
	else if (!f1 && f2) cout << "MMYY\n";
	else if (f1 && f2) cout << "AMBIGUOUS\n";
	else if (!f1 && !f2) cout << "NA\n"; 
	return 0;
}