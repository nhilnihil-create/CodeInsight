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

int char2int(char c) {
	return (int)c - (int)'0';
}
int main() {
	int ans = INT_MAX;
	string S; 
	cin >> S;
	for (size_t i = 0; i < S.size() - 2; i++) {
		int num = char2int(S[i]) * 100 + char2int(S[i + 1]) * 10  + char2int(S[i+2]);
		ans = min(ans, abs(num - 753));
	}
	cout << ans << endl;
}