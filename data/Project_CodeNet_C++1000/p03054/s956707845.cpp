#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main() {
	int H, W, N;
	cin >> H >> W >> N;
	int sr, sc;
	cin >> sr >> sc;
	string S, T;
	cin >> S >> T;

	string res = "YES";

	// 左右方向、1から左へ
	int x = sc;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'L') --x;
		if (x <= 0)
			res = "NO";
		if (T[i] == 'R') ++x;
		if (x > W) x = W;
	}
	// 左右方向、Wから右へ
	x = sc;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'R') ++x;
		if (x > W)
			res = "NO";
		if (T[i] == 'L') --x;
		if (x <= 0) x = 1;
	}
	// 上下方法、1から上へ
	int y = sr;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'U') --y;
		if (y <= 0)
			res = "NO";
		if (T[i] == 'D') ++y;
		if (y > H) y = H;
	}
	// 上下方向、Hから下へ
	y = sr;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'D') ++y;
		if (y > H)
			res = "NO";
		if (T[i] == 'U') --y;
		if (y <= 0) y = 1;
	}

	cout << res << endl;

	return 0;
}