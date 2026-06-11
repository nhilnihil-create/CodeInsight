#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <unordered_map>

using namespace std;
using ll = long long;

int main() {
	string S;
	cin >> S;
	string T;
	int ans = 0;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j <= S.size() - i; j++) {
			T = S.substr(i, j);
			bool ok = true;
			for (char c : T) {
				if (c != 'A' && c != 'C' && c != 'G' && c != 'T') ok = false;
			}
			if (ok) ans = max(ans, (int)T.size());
		}
	}
	cout << ans << endl;
	return 0;
}