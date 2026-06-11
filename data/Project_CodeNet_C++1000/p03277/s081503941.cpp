#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int n, a[2100009], b[100009], N, c[100009], s[100009], NN, ori[100009];
vector<int> vec;
map<int, int> mp, rmp;
long long tot;

void upd(int x, int v)
{
	x += NN;
	while (x) {
		a[x] += v;
		x = x / 2;
	}
}

int query(int A, int B, int l, int r, int x)
{
	if (l >= r) return 0;
	if (l <= A && B <= r) return a[x];
	int mid = (A + B) / 2;
	int retL = 0, retR = 0;
	if (l < mid) retL = query(A, mid, l, r, x + x);
	if (mid < r) retR = query(mid, B, l, r, x + x + 1);
	return retL + retR;
}

long long fun(int v)
{
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] >= v) c[i] = 1;
		else c[i] = -1;
	}
	s[0] = c[0];
	for (int i = 1; i < n; i++) {
		s[i] = s[i - 1];
		s[i] += c[i];
	}
	for (int i = 0; i < 2 * NN; i++) {
		a[i] = 0;
	}
	upd(s[0] + n, 1);
	if (s[0] >= 0) cnt++;
	for (int i = 1; i < n; i++) {
		int tmp = query(0, NN, 0, s[i] + n + 1, 1);
		cnt += tmp;
		if (s[i] >= 0) cnt++;
		upd(s[i] + n, 1);
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ori[i];
		vec.pb(ori[i]);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	for (int i = 0; i < (int)vec.size(); i++) {
		mp[vec[i]] = i;
		rmp[i] = vec[i];
	}
	for (int i = 0; i < n; i++) {
		b[i] = mp[ori[i]];
	}
	N = 1;
	while (N < n + 1) N = N << 1;
	NN = N << 1;
	tot = (n) * 1LL * (n - 1) / 2 + n;
	int l = 0, r = (int)vec.size();
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		long long C = fun(mid);
		if (tot - C <= C) l = mid;
		else r = mid;
	}
	cout << rmp[l] << E;
	//system("pause");
	return 0;
}