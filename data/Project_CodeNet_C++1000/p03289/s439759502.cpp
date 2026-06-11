#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	string S;
	cin >> S;
	int n = (int)S.size();
	string ans = "WA";
	if (S[0] == 'A') {
		int count_C = 0;
		for (int i = 2; i < n - 1; i++) {
			if (S[i] == 'C') count_C++;
		}
		if (count_C == 1) {
			bool ok = true;
			for (int i = 1; i < n; i++) {
				if ('A' <= S[i] && S[i] <= 'Z') {
					if (S[i] == 'C' && (2 <= i && i < n - 1)) continue;
					else ok = false;
				}
			}
			if (ok) ans = "AC";
		}
	}
	cout << ans << endl;
	return 0;
}