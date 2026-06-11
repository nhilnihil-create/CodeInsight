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
	int N;
	cin >> N ;
	vector<int>A(N);
	for (int n = 0;n<N;++n) {
		cin >> A[n];
	}
	int ans = 0;	
	for (int n = 0; n < N; ++n) {
		ans = gcd(A[n],ans);
	}
	cout << ans;
}
