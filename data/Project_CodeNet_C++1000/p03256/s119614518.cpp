#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A[200009], B[200009], dega[200009], degb[200009]; char c[200009]; bool used[200009]; vector<int>X[200009];
queue<int>Q;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> c[i];
	for (int i = 0; i < M; i++) {
		cin >> A[i] >> B[i];
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < X[i].size(); j++) {
			if (c[X[i][j]] == 'A') dega[i]++;
			if (c[X[i][j]] == 'B') degb[i]++;
		}
		if (dega[i] <= 0 || degb[i] <= 0) { Q.push(i); used[i] = true; }
	}
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int i = 0; i < X[pos].size(); i++) {
			if (c[pos] == 'A') dega[X[pos][i]]--;
			else degb[X[pos][i]]--;
			if ((dega[X[pos][i]] <= 0 || degb[X[pos][i]] <= 0) && used[X[pos][i]] == false) { 
				Q.push(X[pos][i]); used[X[pos][i]] = true;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (used[i] == false) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}