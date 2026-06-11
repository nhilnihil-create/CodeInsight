#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int ans = 0;
	for (int ii = 0; ii <= N/R; ++ii){
		int val1 = ii*R;
		for (int jj = 0; jj <= N/G; ++jj){
			int val2 = jj*G;
			if (val1 + val2 > N){
				break;
			}

			int rem = N - val1 - val2;
			if (rem % B == 0){
				ans++;
			}
		}
	}

	cout << ans << "\n";		

	return 0;
}
