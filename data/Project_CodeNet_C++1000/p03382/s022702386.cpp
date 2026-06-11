#include <bits/stdc++.h>
#define INFLL (0x3f3f3f3f)
using namespace std;
typedef long long ll;

ll A[100055];

ll Mx, T, L = INFLL;
int N;

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		if(Mx < A[i]) Mx = A[i];
	}
	for(int i = 0; i < N; i++) {
		ll t = abs(A[i]*2 - Mx);
		if(L <= t || Mx == A[i]) continue;
		L = t; T = A[i];
	}

	cout << Mx << " " << T << endl;
	return 0;
}