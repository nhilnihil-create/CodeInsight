#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	int N = S.size();
	if (S[0] == '0' || S[N - 1] == '1') {
		cout << -1 << endl;
		return 0;
	}
	S = S.substr(0, N - 1);
	string T = S;
	reverse(T.begin(), T.end());
	if (S != T) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> V;
	for (int i = 0; i * 2 + 1 < N; i++) {
		if (S[i] == '1') V.push_back(i);
	}
	V.push_back(V[V.size() - 1] + 1);
	for (int i = V[V.size() - 1] + 1; i < N; i++) {
		cout << V[V.size() - 1] + 1 << " " << i + 1 << endl;
	}
	int NOW = 0;
	for (int i = V[V.size() - 1] - 1; i >= 0; i--) {
		if (S[i] == '1') NOW = i;
		else cout << i + 1 << " " << NOW + 1 << endl;
	}
	for (int i = 0; i < V.size() - 1; i++) {
		cout << V[i] + 1 << " " << V[i + 1] + 1 << endl;
	}
}