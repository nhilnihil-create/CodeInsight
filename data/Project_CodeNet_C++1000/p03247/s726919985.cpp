#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
int X[1000], Y[1000], P[1000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		P[i] = (abs(X[i]) + abs(Y[i])) % 2;
		if (P[i] != P[0]) {
			cout << -1 << endl;
			return 0;
		}
	}
	vector<int> arm;
	for (int i = 30; i >= 0; i--) arm.push_back(1 << i);
	if (!P[0]) arm.push_back(1);
	cout << arm.size() << endl;
	for (int i = 0; i < arm.size(); i++) {
		if (i > 0) cout << " ";
		cout << arm[i];
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		int tx = X[i] - Y[i], ty = X[i] + Y[i];
		vector<bool> x(arm.size()), y(arm.size());
		for (int j = 0; j < arm.size(); j++) {
			if (tx >= 0) tx -= arm[j], x[j] = 1;
			else tx += arm[j], x[j] = 0;
			if (ty >= 0) ty -= arm[j], y[j] = 1;
			else ty += arm[j], y[j] = 0;
		}
		for (int j = 0; j < arm.size(); j++) {
			if (x[j]) {
				if (y[j]) cout << "R";
				else cout << "D";
			}
			else {
				if (y[j]) cout << "U";
				else cout << "L";
			}
		}
		cout << endl;
	}
}
