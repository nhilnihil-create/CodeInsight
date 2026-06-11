#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
    int x = 0, fh = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            fh = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * fh;
}
const int N = 1010;
int n, m, sum, ans, i, a[N];
int main() {
	n = read(); m = read();
	for (i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + 1 + n);
	for (i = 1; i <= n; i++) sum += a[i];
	ans += (m - sum) / a[1] + n;
	cout << ans;
	return 0;
}