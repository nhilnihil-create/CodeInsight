#include "bits/stdc++.h"

using namespace std;
int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	int rB = 0;
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '#') {
			rB++;
		}
	}
	int rW = N - rB;
	int lB = 0;
	int lW = 0;
	int ans = rW + lB;
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '.') {
			rW--;
			lW++;
		}
		else {
			rB--;
			lB++;
		}
		ans = min(ans, lB + rW);
	}
	cout << ans <<  endl;
}
