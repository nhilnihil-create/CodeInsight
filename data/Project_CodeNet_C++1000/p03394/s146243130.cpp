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
int main() {
	int n; read(n);
	if (n == 3) {
		puts("2 5 63");
		return 0;
	}
	int base = 0;
	while (n >= 8) {
		n -= 8;
		printf("%d %d %d %d %d %d %d %d ", base + 2, base + 3, base + 4, base + 6, base + 8, base + 9, base + 10, base + 12);
		base += 12;
	}
	if (n == 1) printf("%d\n", base + 6);
	else if (n == 2) printf("%d %d\n", base + 2, base + 4);
	else if (n == 3) printf("%d %d %d\n", base + 2, base + 4, base + 6);
	else if (n == 4) printf("%d %d %d %d\n", base + 2, base + 3, base + 4, base + 9);
	else if (n == 5) printf("%d %d %d %d %d\n", base + 2, base + 3, base + 4, base + 6, base + 9);
	else if (n == 6) printf("%d %d %d %d %d %d\n", base + 2, base + 3, base + 4, base + 6, base + 9, base + 12);
	else if (n == 7) printf("%d %d %d %d %d %d %d\n", base + 2, base + 3, base + 4, base + 6, base + 8, base + 9, base + 10);
	return 0;
}