#include "bits/stdc++.h"
using namespace std;


int main() {
	int N;
	string S;
	cin >> N >> S;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		vector<int>A(26);
		vector<int>B(26);
		for (int j = 0; j < N; ++j) {
			if (j < i) {
				A[S[j] - 'a']++;
			}
			else {
				B[S[j] - 'a']++;
			}
		}
		int anstmp = 0;
		for (int j = 0; j < 26; ++j) {
			if (A[j] > 0 && B[j] > 0) {
				++anstmp;
			}
		}
		ans = max(ans, anstmp);
	}
	cout << ans << endl;
}
