#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll gcd(ll a, ll b) {
   if (a % b == 0) {
       return(b);
   } else {
       return(gcd(b, a % b));
   }
}

int main() {
	int N;
	cin >> N;

	vector <int> A(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> A[ii];
	}

	//前計算
	vector <int> L(N, 0);
	L[1] = A[0];
	for (int ii = 2; ii < N; ++ii){
		L[ii] = gcd(L[ii-1], A[ii-1]);
	}

	vector <int> R(N, 0);
	R[N-2] = A[N-1];
	for (int ii = N-2; ii >= 0; --ii){
		R[ii] = gcd(R[ii+1], A[ii+1]);
	}

	int ans = 1;
	for (int ii = 0; ii < N; ++ii){
		int tmp;
		if (L[ii] == 0){
			tmp = R[ii];
		} else if (R[ii] == 0) {
			tmp = L[ii];
		} else {
			tmp = gcd(L[ii], R[ii]);
		}
		ans = max(ans, tmp);
	}

	cout << ans << "\n";

	return 0;
}
