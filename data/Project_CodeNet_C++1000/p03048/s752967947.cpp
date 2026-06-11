#include <bits/stdc++.h>
using namespace std;

int main() {
	long long R, G, B, N, ans = 0;
	cin >> R >> G >> B >> N;
	for (int r = 0; r <= N / R; r++) {
		for (int g = 0; g <= (N - r * R) / G; g++) {
			if ((N - r * R - g * G) % B == 0) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
