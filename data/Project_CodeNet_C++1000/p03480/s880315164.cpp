#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int main(int argc, char** argv) {
	string S;

	cin >> S;


	long long len = S.length();
	long long ans = len;

	for (long long i = 0; i < len - 1; i++) {
		if (S[i] != S[i + 1]) {
			ans = min(ans, max(i + 1, len - i - 1));
		}
	}
	cout << ans << endl;

}