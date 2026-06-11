#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string S;
	cin >> S;
	int win = 0;
	rep(i, S.size()) {
		if (S.at(i) == 'o') win++;
	}
	cout << (8 - win <= 15 - S.size() ? "YES" : "NO") << endl;
	return 0;
}