#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int n, k, q, a[2019], b[2019];
multiset<int> mst, tst;

void gun(int ss, int ee)
{
	int cnt = ee - ss + 1;
	cnt = cnt - k + 1;
	if (cnt <= 0) return;
	tst.clear();
	for (int i = ss; i <= ee; i++) {
		if (tst.size() == cnt) {
			auto x = tst.end();
			x--;
			if (*x > a[i]) {
				tst.erase(x);
				tst.insert(a[i]);
			}
		}
		else {
			tst.insert(a[i]);
		}
	}
	for (auto y : tst) {
		if (mst.size() == q) {
			auto x = mst.end();
			x--;
			if (*x > y) {
				mst.erase(*x);
				mst.insert(y);
			}
		}
		else {
			mst.insert(y);
		}
	}
}

int fun(int x)
{
	int ss = 0, ee = 0;
	mst.clear();
	while (1) {
		while (ss < n && a[ss] < x) {
			ss++;
		}
		if (ss == n) break;
		ee = ss;
		while (ee + 1 < n && a[ee + 1] >= x) {
			ee++;
		}
		gun(ss, ee);
		ss = ee + 1;
	}
	if ((int)mst.size() == q) {
		auto x = mst.begin();
		int tmp = *x;
		x = mst.end();
		x--;
		tmp = *x - tmp;
		return tmp;
	}
	else return 1e9;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i + 1] = a[i];
	}
	sort(b, b + n + 1);
	int ans = MOD;
	for (int i = 0; i < n + 1; i++) {
		ans = min(ans, fun(b[i]));
	}
	cout << ans << E;
	//system("pause");
	return 0;
}