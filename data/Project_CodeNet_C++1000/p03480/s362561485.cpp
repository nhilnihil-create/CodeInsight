#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	int memo = 0;
	int r = (S.size() + 1) / 2;
	int l = r - 1;
	char c = S[l];
	if (1 == S.size() % 2) {
		memo++;
		l--;
	}

	while ((c == S[r]) && (c == S[l])) {
		memo += 2;
		l--;
		r++;
		if (l < 0) {
			break;
		}
	}
	cout << (S.size() + memo) / 2 << endl;
	return 0;
}