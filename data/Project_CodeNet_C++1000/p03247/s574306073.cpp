#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

signed main() {
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for(int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	int p = (abs(X[0]) + abs(Y[0])) % 2;
	for(int i = 0; i < N; ++i) {
		if (p != (abs(X[i]) + abs(Y[i])) % 2) {
			cout << -1 << endl;
			return 0;
		}
	}
	int m = 36;
	vector<int> d(m);
	for(int i = 0; i < m - 1; ++i) {
		d[i] = 1LL << (m - 2 - i);
	}
	d[m - 1] = 1;
	if (p) {
		cout << m + 1 << endl;
		cout << "1 ";
	} else {
		cout << m << endl;
	}
	for(int i = 0; i < m; ++i) {
		cout << d[i] << (i == m -1 ? "\n": " ");
	}

	for(int i = 0; i < N; ++i) {
		int x, y;
		x = y = 0;
		if(p) {
			X[i]--;
			cout << "R";
			++x;
		}
		int U = X[i] + Y[i], V = X[i] - Y[i];
		vector<int> a(m), b(m);
		for(int j = 0; j < m; ++j) {
			if(U >= 0) {
				a[j] = 0;
				U -= d[j];
			} else {
				a[j] = 1;
				U += d[j];
			}
			if (V >= 0) {
				b[j] = 0;
				V -= d[j];
			} else {
				b[j] = 1;
				V += d[j];
			}
			if (a[j] == 0 && b[j] == 0) {
				x += d[j];
				cout << "R";
			} else if (a[j] == 0 && b[j] == 1) {
				y += d[j];
				cout << "U";
			} else if (a[j] == 1 && b[j] == 0) {
				y -= d[j];
				cout << "D";
			} else {
				x -= d[j];
				cout << "L";
			}
			//cerr << " " << x << "," << y << " " << U << "," << V << endl;
		}
		cout << endl;
	}
	return 0;
}