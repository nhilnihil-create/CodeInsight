#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int H, W;
string S[50];

int countBombs(int i, int j) {
	int cnt = 0;
	for (int m = max(0, i - 1); m < min(H, i + 2); m++) {
		for (int n = max(0, j - 1); n < min(W, j + 2); n++) {
			if (S[m][n] == '#') cnt++;
		}
	}
	return cnt;
}

int main(void) {
	scanf("%d %d", &H, &W);
	for (int i = 0; i < H; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#') continue;
			S[i][j] = '0' + countBombs(i, j);
		}
		cout << S[i] << "\n";
	}
	return 0;
}
