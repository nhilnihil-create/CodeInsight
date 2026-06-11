#include <bits/stdc++.h>
#include <bits/extc++.h>
#define lowbit(x) ((x) & -(x))
#define gr(a, b) ((a) > (b) ? 1 : (a) == (b) ? 0 : -1)
using namespace std;

int n;
int a[100010];
int c[200010];
char check(const int &x);
void insert(const int &x);
int query(const int &x);

int main() {
	scanf("%d", &n);
	int l = 1000000000, r = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		l = min(l, a[i]), r = max(r, a[i]);
	}
	
	while (l <= r) {
		int m = l + r >> 1;
		if (check(m))
			l = m + 1;
		else
			r = m - 1;
	}
	printf("%d\n", r);
	return 0;
}

char check(const int &x) {
	int sum = 0;
	long long tot = 0;
	memset(c, 0, sizeof(c));
	insert(0);
	for (int i = 0; i < n; ++i) {
		sum += a[i] >= x ? 1 : -1;
		tot += query(sum);
		insert(sum);
	}
	return tot << 2 >= 1ll * n * (n + 1);
}

void insert(const int &x) {
	for (int i = x + n + 1; i <= (n << 1 ^ 1); i += lowbit(i))
		++c[i];
}

int query(const int &x) {
	int ret = 0;
	for (int i = x + n + 1; i > 0; i -= lowbit(i))
		ret += c[i];
	return ret;
}

