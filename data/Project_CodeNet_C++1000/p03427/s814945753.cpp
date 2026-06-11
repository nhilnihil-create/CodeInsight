#include "bits/stdc++.h"
using namespace std;
int main() {
	string S; cin >> S;
	long long ans = 0, sum = 0;
	for (long long i = 0; i < S.size(); i++) {
		sum += (S.at(i) - '0');
		if (i == 0) {
			ans += (S.at(i) - '0') - 1;
		}
		else ans += 9;
	}
	cout << max(ans,sum) << endl;
}
