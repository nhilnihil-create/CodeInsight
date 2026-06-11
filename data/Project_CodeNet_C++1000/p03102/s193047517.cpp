#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, M, C;
	cin >> N >> M >> C;

	vector <int> B(M);
	for (int ii = 0; ii < M; ++ii){
		cin >> B[ii];
	}

	int ans = 0;
	for (int ii = 0; ii < N; ++ii){
		int val = 0;
		for (int jj = 0; jj < M; ++jj){
			int A;
			cin >> A;
			val += A*B[jj];
		}
		if (val > -C){
			ans++;
		}
	}


	cout << ans << "\n";

	return 0;
}
