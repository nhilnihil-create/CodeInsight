#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#define BUF 50
using namespace std;
ll MOD = 1e9 + 7;
ll A, B, C, D, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S;
ll ans = 0;

int main() {
	cin >> A >> B;
	A--; B--;
	cout << 100 << " " << 100 << endl;
	ll fr = A / 50;
	for (int i = 0; i < 2*fr+1; i++) {
		ans++;
		if (i & 1) {
			for (int j = 0; j < 50; j++) {
				cout << '#' << '.';
			}
			cout << endl;
		}
		else {
			for (int j = 0; j < 50; j++) {
				cout << '#' << '#';
			}
			cout << endl;
		}
	}
	int ba = A % 50;
	if (ba != 0) {
		for (int i = 0; i < 50; i++) {
			if (i < ba)
				cout << '#' << '.';
			else cout << '.' << '.';
		}
		cout << endl;
		ans++;
	}
	for (int j = 0; j < 50; j++) {
		cout << '#' << '#';
	}
	cout << endl;
	ans++;
	for (int j = 0; j < 50; j++) {
		cout << '.' << '.';
	}
	cout << endl;
	ans++;

	fr = B / 50;
	for (int i = 0; i < 2*fr+1; i++) {
		ans++;
		if (i & 1) {
			for (int j = 0; j < 50; j++) {
				cout << '#' << '.';
			}
			cout << endl;
		}
		else {
			for (int j = 0; j < 50; j++) {
				cout << '.' << '.';
			}
			cout << endl;
		}
	}
	ba = B % 50;
	if (ba != 0) {
		for (int i = 0; i < 50; i++) {
			if (i < ba)
				cout << '#' << '.';
			else cout << '.' << '.';
		}
		cout << endl;
		ans++;
	}
	for (int i = 0; i < 100 - ans; i++) {
		for (int j = 0; j < 50; j++) {
			cout << '.' << '.';
		}
		cout << endl;
	}
}