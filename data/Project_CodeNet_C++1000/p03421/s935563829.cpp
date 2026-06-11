#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, A, B, X, Y, Cur = 1;
	vector<long long> V;
	vector<vector<long long> > ANS;
	cin >> N >> A >> B;
	if (A * B < N || N + 1 < A + B) {
		cout << -1 << endl;
		return 0;
	}
	X = N, Y = B;
	for (int i = 0; i < B; i++) {
		if (X == Y) {
			V.push_back(1);
			X--, Y--;
		}
		else if (X - A >= Y - 1) {
			V.push_back(A);
			X -= A;
			Y--;
		}
		else {
			V.push_back(X - Y + 1);
			Y--;
			X = Y;
		}
	}
	for (int i = 0; i < B; i++) {
		vector<long long> VV = {};
		for (int j = 0; j < V[i]; j++) {
			VV.push_back(Cur);
			Cur++;
		}
		ANS.push_back(VV);
	}
	for (int i = B - 1; i >= 0; i--) {
		for (int j = 0; j < ANS[i].size(); j++) {
			cout << ANS[i][j];
			if (i == 0 && j == ANS[i].size() - 1) cout << endl;
			else cout << " ";
		}
	}
}