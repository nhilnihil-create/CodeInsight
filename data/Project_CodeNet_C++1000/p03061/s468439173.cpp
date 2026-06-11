#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
#define deps(i, a, n) for (int i = (a); i >= (n); --i)
#define dep(i, n) deps(i, n, 0)
#define inf 2147483647
#define int long long

signed main(void)
{
	int n; cin >> n;
	int a[100005];
	rep (i, n) cin >> a[i];

	int gl[100005], gr[100005];
	gl[0] = 0, gl[1] = a[0];
	gr[n - 1] = 0, gr[n - 2] = a[n - 1];
	reps (i, 2, n)
	{
		gl[i] = __gcd(gl[i - 1], a[i - 1]);
		gr[n - i - 1] = __gcd(gr[n - i], a[n - i]);
	}
	//rep (i, n) cout << gl[i] << ", " << gr[i] << endl;

	int ans;
	ans = gl[n - 1] > gr[0] ? gl[n - 1] : gr[0];
	reps (i, 1, n - 1)
	{
		int tmp;
		tmp = __gcd(gl[i], gr[i]);
		if (tmp > ans) ans = tmp;
	}
	cout << ans << endl;
}
