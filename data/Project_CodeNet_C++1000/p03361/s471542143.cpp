#include <bits/stdc++.h>
using namespace std;

#define MAX 50

int main() {
	int H, W;
	string s[MAX];
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> s[i];
	}
	bool ans = true;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (s[i][j] == '.')
				continue;
			bool flg = false;
			if (i - 1 >= 0 && s[i - 1][j] == '#')
				flg = true;
			if (i + 1 < H && s[i + 1][j] == '#')
				flg = true;
			if (j - 1 >= 0 && s[i][j - 1] == '#')
				flg = true;
			if (j + 1 < W && s[i][j + 1] == '#')
				flg = true;
			ans = ans && flg;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
