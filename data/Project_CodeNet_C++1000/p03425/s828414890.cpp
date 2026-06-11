#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long>S(5);
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		if ('M' == s[0]) {
			S[0]++;
		}
		else if ('A' == s[0]) {
			S[1]++;
		}
		else if ('R' == s[0]) {
			S[2]++;
		}
		else if ('C' == s[0]) {
			S[3]++;
		}
		else if ('H' == s[0]) {
			S[4]++;
		}
	}
	long long ans = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			for (int k = j + 1; k < 5; ++k) {
				ans += S[i] * S[j] * S[k];
			}
		}
	}
	cout << ans << endl;
	return 0;
}