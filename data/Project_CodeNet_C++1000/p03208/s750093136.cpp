#include <bits/stdc++.h>

using namespace std;

int main() {
	int K, N; cin >> N >> K;
	int h[N];
	for (int i = 0; i < N; i++) cin >> h[i];
	sort(h, h+N);
	// int index = 0;
	int min = h[N-1] - h[0] + 1;
	for (int i = 0; i <= N - K; i++) {
		int dif = h[i+K-1] - h[i];
		if (dif < min) {min = dif;}
	}
	cout << min;
	return 0;
}