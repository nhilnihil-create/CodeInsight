#include "bits/stdc++.h"
using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int N, X;
	cin >> N >> X;
	vector<int>Num(N);
	for (int n = 0;n<N;++n) {
		cin >> Num[n];
	}
	int ans = 0;
	for (int n = 0; n < N; ++n) {
		ans = gcd(ans,abs(X-Num[n]));
	}
	cout << ans << endl;
	return 0;
}