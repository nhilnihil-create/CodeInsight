#include <bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;

#define debug printf("fuck %d\n", __LINE__);

inline LL read() {
	LL res = 0, bo = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if (ch == '-') bo = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { res = (res << 1) + (res << 3) + ch - '0'; ch = getchar(); }
	return bo * res;
}

template<typename T> void read(T &x) { x = read(); }
template<typename T, typename ...Argv> void read(T &a, Argv &...argv) { read(a); read(argv...); }

const int N = 4e5 + 100;

struct node {
	int pos, val;
	node() {}
	node(int pos, int val) : pos(pos), val(val) {}
} s[N];

int a[N], top, n;

void insert(int pos, int val) {
	while (top > 1 && s[top].pos > pos) -- top;
	if (s[top].pos == pos) ++ s[top].val;
	else s[++ top] = node(pos, 1);
	if (top > 1 && s[top].val >= val) -- top, insert(pos - 1, val);
}

bool check(int x) {
	s[top = 1] = node(0, 0);
	for (int i = 2; i <= n; ++ i) if (a[i] <= a[i - 1]) insert(a[i], x);
	return s[1].val == 0;
}

int main() {
	n = read();
	for (int i = 1; i <= n; ++ i) a[i] = read();
	int flag = 1;
	for (int i = 2; i <= n; ++ i) if (a[i] <= a[i - 1]) flag = 0;
	if (flag) return puts("1"), 0;
	int l = 2, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	std::cout << r + 1 << std::endl;
	return 0;
}