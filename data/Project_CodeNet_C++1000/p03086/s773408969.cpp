#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	string S, ACGT = "ACGT";
	cin >> S;
	int ans = 0;
	int now = 0;
	for(char c : S) {
		if (ACGT.find(c) != string::npos) {
			now++;
			ans = max(ans, now);
		}
		else {
			now = 0;
		}
	}
	cout << ans << endl;
}