#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, q;
char s[MAXN], c[MAXN], opt[MAXN];
bool gol(int pos) {
	for (int i = 1; i <= q; i++) {
		if (c[i] == s[pos]) {
			if (opt[i] == 'L') pos--;
			else pos++;
		}
		if (pos > n) return false;
		if (pos < 1) return true;
	}
	return false;
}
bool gor(int pos) {
	for (int i = 1; i <= q; i++) {
		if (c[i] == s[pos]) {
			if (opt[i] == 'L') pos--;
			else pos++;
		}
		if (pos > n) return true;
		if (pos < 1) return false;
	}
	return false;
}
int getl() {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (gol(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}
int getr() {
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (gor(mid)) r = mid;
		else l = mid + 1;
	}
	return n + 1 - l;
}
int main() {
	read(n), read(q);
	scanf("\n%s", s + 1);
	for (int i = 1; i <= q; i++)
		scanf("\n%c %c", &c[i], &opt[i]);
	writeln(n - getl() - getr());
	return 0;
}