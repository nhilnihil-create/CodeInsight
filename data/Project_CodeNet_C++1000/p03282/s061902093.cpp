#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	string S; cin >> S;
	long long K; cin >> K;
	for (long long i = 0; i < K; i++) {
		if(S.at(i) != '1') {
			cout << S.at(i) << endl;
			return 0;
		}
	}
	cout << 1 << endl;
}
