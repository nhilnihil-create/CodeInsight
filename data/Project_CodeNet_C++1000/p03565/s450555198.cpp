#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
using namespace std;

int main() {

	string S, T;
	cin >> S >> T;

	// 文字列 S が存在するかどうかのフラグ
	bool jdg = false;

	int ib = 0;

	// 文字列 T の探索
	for (int i = S.length() - T.length(); i >= 0; i--) {
		jdg = true;
		// 文字列Tと一致するかどうかの探索
		for (int j = 0; j < T.length(); j++) {
			if (S[i + j] == '?') {
				continue;
			}
			else if (S[i + j] != T[j]) {
				jdg = false;
				break;
			}
		}
		if (jdg == true) {
			ib = i;
			break;
		}
	}

	if (jdg == true) {
		// 文字列 S の探索
		for (int i = 0; i < S.length(); i++) {
			if (S[i] == '?') {
				S[i] = 'a';
			}
		}
		for (int i = ib; i < ib + T.length(); i++) {
			S[i] = T[i - ib];
		}

		cout << S << endl;
	}
	else {
		cout << "UNRESTORABLE" << endl;
	}

	return 0;
}

