#include<bits/stdc++.h>
using namespace std;
#define MaxN 100010
#define ll long long

int n, l, r, ans, a[MaxN], s[MaxN * 10];
ll tr[MaxN * 10];

int read() {
	int res = 0, flag = 1; char ch;
	ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		res = res * 10 + ch - '0';
		ch = getchar();
	}
	return res * flag;
}

void add(int x) {
	for (; x <= MaxN * 2; x += x & -x)
		tr[x]++;
}

ll ask(int x) {
	ll res = 0;
	for (; x; x -= x & -x)
		res += tr[x];
	return res;
}

bool check(int val) {
	ll res = 0;
	memset(tr, 0, sizeof(tr));
	for (int i = 1; i <= n; i++)
		if (a[i] < val) s[i] = s[i - 1] - 1;
		else s[i] = s[i - 1] + 1;
	for (int i = 0; i <= n; i++) {
		res += ask(s[i] + MaxN);
		add(s[i] + MaxN);
	}
	return res >= (ll) n * (n + 1) / 4;
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), r = max(a[i], r);
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}