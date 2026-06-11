#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int H, W;
	cin >> H >> W;

	vector<vector<char>> v(H + 2, vector<char>(W + 2));
	for (int i = 0; i < H + 2; i++) {
		for (int j = 0; j < W + 2; j++) {
			v.at(i).at(j) = '.';
		}
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> v.at(i).at(j);
		}
	}

	//for (int i = 0; i < H + 2; i++) {
	//	for (int j = 0; j < W + 2; j++) {
	//		cout << v.at(i).at(j);
	//	}
	//	cout << endl;
	//}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			char ch = v.at(i).at(j);
			if (ch == '#') {
				bool b = false;
				if (v.at(i - 1).at(j) == '#') b = true;
				if (v.at(i + 1).at(j) == '#') b = true;
				if (v.at(i).at(j - 1) == '#') b = true;
				if (v.at(i).at(j + 1) == '#') b = true;
				
				if (!b) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}

	cout << "Yes" << endl;
}