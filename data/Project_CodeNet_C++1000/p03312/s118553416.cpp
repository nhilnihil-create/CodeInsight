#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

long long n, a[200009], s[200009], ans;

long long cntD(int L, int R, int m)
{
	long long tL = s[m];
	if (L) tL -= s[L - 1];
	long long tR = s[R] - s[m];
	return abs(tL - tR);
}

long long fun(int L, int R)
{
	int l = L, r = R;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (cntD(L, R, mid) < cntD(L, R, mid - 1)) l = mid;
		else r = mid;

	}
	return min(s[l] - s[L - 1], s[R] - s[l]);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i];
		s[i] += s[i - 1];
	}
	ans = 1e18;
	for (int i = 2; i < n - 1; i++) {
		long long mi = fun(1, i);
		long long mx = s[i] - mi;
		long long tmp = fun(i + 1, n);
		mi = min(mi, tmp);
		mx = max(mx, s[n] - s[i] - tmp);
		ans = min(ans, mx - mi);
	}
	cout << ans << E;
	//system("pause");
	return 0;
}