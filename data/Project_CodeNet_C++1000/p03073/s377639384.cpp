#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	int ans0 = 0;
	for (int n = 0;n<S.size();++n) {
		if (1 == n%2) {
			if ('0' != S[n]) {
				ans0++;
			}
		}
		else {
			if ('1' != S[n]) {
				ans0++;
			}
		}
	}
	int ans1 = 0;
	for (int n = 0; n < S.size(); ++n) {
		if (1 == n % 2) {
			if ('1' != S[n]) {
				ans1++;
			}
		}
		else {
			if ('0' != S[n]) {
				ans1++;
			}
		}
	}
	cout << min(ans0,ans1) <<endl;
}
