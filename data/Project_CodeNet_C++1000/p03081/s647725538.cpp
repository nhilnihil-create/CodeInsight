#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int n, m, ansl, ansr, mid;
char s[MAXN];
struct node {
	char c, d;
} q[MAXN];

bool check(int pos)
{
	int x = mid;
	for (int i = 1; i <= m; i++) {
		if (s[x] == q[i].c) {
			q[i].d == 'L' ? --x : ++x;
			if (x < 1 || x > n)return x == pos;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie();
	cin >> n >> m >> s + 1;
	for (int i = 1; i <= m; i++)cin >> q[i].c >> q[i].d;
	int l = 1, r = n, ansl = 0;
	while (l <= r) {
		mid = (l + r) >> 1;
		check(0) ? (ansl = mid, l = mid + 1) : r = mid - 1;
	}
	l = 1, r = n, ansr = n + 1;
	while (l <= r) {
		mid = (l + r) >> 1;
		check(n + 1) ? (ansr = mid, r = mid - 1) : l = mid + 1;
	}
	cout << ansr - ansl - 1;
	return 0;
}