#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;

	vector <ll> V(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> V[ii];
	}

	vector <ll> C(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> C[ii];
	}

	ll ans = 0;
	for (int ii = 0; ii < (1<<N); ++ii){
		int ref = ii;
		ll X = 0;
		ll Y = 0;
		for (int jj = 0; jj < N; ++jj){
			if (ref & 1){
				X += V[jj];
				Y += C[jj];
			}
			ref = ref >> 1;
		}
		ans = max(ans, X - Y);
	}

	cout << ans << "\n";

	return 0;
}
