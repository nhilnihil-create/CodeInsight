#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<vector<char>> field;

bool is_sym(const vector<vector<char>>& F, int ch, int cw) {
	for (int i = ch; i < N + ch; i++) {
		for (int j = cw; j < N + cw; j++) {
			if (F[i % N][j % N] != F[(j - cw + ch) % N][(i - ch + cw) % N]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> N;
	field.resize(N);
	for (int i = 0; i < N; i++) {
		field[i].resize(N);
		for (int j = 0; j < N; j++)cin >> field[i][j];
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (is_sym(field, 0, i)) {
			ans += (N - i);
		}
	}

	for (int i = 1; i < N; i++) {
		if (is_sym(field, i, 0)) {
			ans += (N - i);
		}
	}
	cout << ans << endl;
	return 0;
}