#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct point {
	int x, y, id;
} a[MAXN], b[MAXN];

bool vis[MAXN];
int n;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
		b[i] = a[i];
	}
	sort(a+1, a+n+1, [](const point &a, const point &b) { return a.y < b.y; });
	sort(b+1, b+n+1, [](const point &a, const point &b) { return a.x > b.x; });
	int L = 1, R = 1, cur_pos = 0;
	long long ans = 0;
	auto trans = [&ans](int &x, const point &a) {
		vis[a.id] = 1;
		if (x < a.x) ans += a.x-x, x = a.x;
		else if (x > a.y) ans += x-a.y, x = a.y;
	};
        while (L <= n && R <= n) {
		while (L <= n && vis[a[L].id]) L++;
		if (L <= n) trans(cur_pos, a[L++]);
		while (R <= n && vis[b[R].id]) R++;
		if (R <= n) trans(cur_pos, b[R++]);
	}
	ans += abs(cur_pos);
	long long tot = ans;
	ans = 0, memset(vis, 0, sizeof vis), L = R = 1;
	cur_pos = 0;
	while (L <= n && R <= n) {
		while (R <= n && vis[b[R].id]) R++;
		if (R <= n) trans(cur_pos, b[R++]);
		while (L <= n && vis[a[L].id]) L++;
		if (L <= n) trans(cur_pos, a[L++]);
	}
	ans += abs(cur_pos);
	ans = max(ans, tot);
	cout << ans << endl;
	return 0;
}
