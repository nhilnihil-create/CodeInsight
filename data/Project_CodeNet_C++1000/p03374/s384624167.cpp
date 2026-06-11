#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

long long n, c, x[100009], v[100009], ans, acc[2][100009], dat[2][100009];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> v[i];
	}
	long long tmp = v[0];
	acc[0][0] = tmp - x[0];
	dat[0][0] = acc[0][0];
	for (int i = 1; i < n; i++) {
		tmp += v[i];
		acc[0][i] = tmp - x[i];
		dat[0][i] = max(dat[0][i - 1], acc[0][i]);
	}
	tmp = v[n - 1];
	acc[1][n - 1] = tmp - (c - x[n - 1]);
	dat[1][n - 1] = acc[1][n - 1];
	for (int i = n - 2; i >= 0; i--) {
		tmp += v[i];
		acc[1][i] = tmp - (c - x[i]);
		dat[1][i] = max(dat[1][i + 1], acc[1][i]);
	}
	ans = max(ans, dat[0][n - 1]);
	for (int i = n - 1; i > 0; i--) {
		ans = max(ans, acc[1][i] - (c - x[i]) + dat[0][i - 1]);
	}
	ans = max(ans, dat[1][0]);
	for (int i = 0; i < n - 1; i++) {
		ans = max(ans, acc[0][i] - x[i] + dat[1][i + 1]);
	}
	cout << ans << E;
	//system("pause");
	return 0;
}