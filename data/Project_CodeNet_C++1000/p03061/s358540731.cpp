#include "bits/stdc++.h"
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a; 
	if (a == 0) return b;
	return gcd(b, a%b);
}

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int n = 0;n<N;++n) {
		cin >> A[n];
	}
	vector<int>L(N);	
	L[0] = 0; 
	for (int n = 1; n < N; ++n) {
		L[n] = gcd(A[n-1],L[n - 1]);
	}
	vector<int>R(N);
	R[N - 1] = 0;
	for (int n = 1; n < N; ++n) {
		R[N-1-n] = gcd(A[N - n],R[N-n]);
	}
	int ans = 0;
	for (int n = 0; n < N; ++n) {
		ans = max(ans,gcd(R[n],L[n]));
	}
	cout << ans <<endl;
}
