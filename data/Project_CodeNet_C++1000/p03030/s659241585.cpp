#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<string> S(N); vector<int> P(N);
	for(int i = 0; i < N; ++i) {
		cin >> S[i] >> P[i];
	}
	vector<int> perm(N);
	for(int i = 0; i < N; ++i) {
		perm[i] = i;
	}
	sort(perm.begin(), perm.end(), [&](int i, int j) { return S[i] != S[j] ? S[i] < S[j] : P[i] > P[j]; });
	for(int i = 0; i < N; ++i) {
		cout << perm[i] + 1 << endl;
	}
	return 0;
}