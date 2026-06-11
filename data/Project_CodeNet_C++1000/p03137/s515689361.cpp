#include "bits/stdc++.h"
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

int main() {
	int N,M;
	cin >> N >>M;
	vector<int>X(M);
	for (int n = 0;n<M;++n) {
		cin >> X[n];
	}
	sort(X.begin(),X.end());	
	vector<int>Y(M-1);
	for (int n = 0; n < M-1; ++n) {
		Y[n]=X[n+1]-X[n];
	}
	sort(Y.begin(), Y.end(), greater<int>());
	int res = X.back() - X[0];
	for (int n = 0;n<min(N-1,M - 1);++n) {
		res -= Y[n];
	}
	cout << res << endl;
	return 0;
}
