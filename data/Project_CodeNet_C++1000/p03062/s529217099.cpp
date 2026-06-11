#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;

	vector <ll> A(N);
	vector <ll> absA(N);
	int sign = 0;
	ll ans = 0;
	for (int ii = 0; ii < N; ++ii){
		cin >> A[ii];
		absA[ii] = abs(A[ii]);
		ans += absA[ii];
		if (A[ii] < 0){
			sign ^= 1;
		}
	}

	if (sign){
		sort(absA.begin(), absA.end());
		ans = ans - 2 * absA[0];
	}

	cout << ans << "\n";

	return 0;
}
