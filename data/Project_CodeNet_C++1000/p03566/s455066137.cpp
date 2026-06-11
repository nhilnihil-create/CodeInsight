#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/abc076/tasks/abc076_d

int n, x[103], v[102], m;
double l, r, ans = 0;

double f(double t, int i) {
	if (t < x[i])
		return v[i] + x[i] - t;
	if (t > x[i + 1])
		return v[i] + t - x[i + 1];
	return v[i];
}

double sup(double t) {
	double rv = m;
	for (int i = 0; i < n + 2; i++) {
		double s = f(t, i);
		rv = min(rv, s);
	}
	return rv;
}

int main() {
	cin >> n;
	for (int i = 0, t; i < n; i++) {
		cin >> t;
		x[i + 2] = x[i + 1] + t;
	}
	x[n + 2] = x[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> v[i + 1];
		m = max(m, v[i + 1]);
	}
	for (double t = 0; t < x[n + 1]; t += 0.5)
		ans += sup(t) + sup(t + 0.5);
	cout <<fixed<< ans / 4 << endl;
}
