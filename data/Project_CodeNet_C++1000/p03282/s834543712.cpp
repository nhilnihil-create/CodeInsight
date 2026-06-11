#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	long long K;
	cin >> S >> K;
	int ans = 1;
	for (long long n = 0;n<min(K,(long long)S.size());++n) {
		if (1 != S[n]-'0') {
			ans = S[n] - '0';
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
