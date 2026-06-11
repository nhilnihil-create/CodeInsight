#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N, K;
vector<int> A, B;

ll solve(int x) {
	if (!(K & (1 << x))) return 0;
	int f = (1 << x) - 1;
	for (int i = x + 1; i <= 30; ++i)
		f |= (K & (1 << i));
	ll tmp = 0;
	for (int i = 0; i < N; ++i)
		if ((f | A[i]) == f)
			tmp += B[i];
	return tmp;
}

int main() {
	cin >> N >> K;
	A.resize(N); B.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i] >> B[i];
	ll res = 0;
	for (int i = 0; i < N; ++i) 
		if ((K | A[i]) == K)
			res += B[i];
	for (int x = 30; x > 0; --x)
		res = max(res, solve(x));
	cout << res << endl;
	return 0;
}