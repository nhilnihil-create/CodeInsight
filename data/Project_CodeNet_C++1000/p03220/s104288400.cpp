#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;

	double T, A;
	cin >> T >> A;

	int ans = 0;
	double diff = 100100100;
	for (int ii = 0; ii < N; ++ii){
		double H;
		cin >> H;

		double tmp = T - H * 0.006;
		double tDiff = abs(A - tmp);
		if (tDiff < diff){
			ans = ii;
			diff = tDiff;
		}
	}

	cout << ans + 1 << "\n";

	return 0;
}
