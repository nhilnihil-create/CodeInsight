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
int n, k;
int main() {
	n = read(); k = read();
	cin >> s;
	s[k - 1] += 32;
	cout << s << '\n';
	return 0;
}