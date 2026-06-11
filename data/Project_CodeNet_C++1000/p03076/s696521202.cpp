#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int GetFirstDigitNumber(int N) {
	return N % 10;
}

int main() {

	const int p = 5;
	vector<int> c(p);
	int minDigit = 2147483647;
	int minIndex = -1;
	for (int i = 0; i < p; i++) {
		cin >> c[i];
		int digit = GetFirstDigitNumber(c[i]);
		if (digit != 0 && chmin(minDigit, digit) ) {
			minIndex = i;
		}
	}
	
	int ans = 0;
	if (minIndex == -1) {
		for (int i = 0; i < p; i++) ans += c[i];		
	}
	else {
		for (int i = 0; i < p; i++) {
			if (i == minIndex) continue;
			int digit = GetFirstDigitNumber(c[i]);
			if (digit == 0) ans += c[i];
			else ans += (c[i] / 10 + 1) * 10;
		}
		ans += c[minIndex];
	}

	cout << ans << endl;
	return 0;
}