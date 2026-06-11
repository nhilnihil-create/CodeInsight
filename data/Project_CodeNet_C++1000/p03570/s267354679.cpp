#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int solve(string S) {
	int N = S.size();
	map<int, int> dp;
	dp[0] = 0;
	int bit = 0;
	for (int i = 0; i < N; ++i) {
		bit ^= 1 << (S[i] - 'a');
		int opt = (dp.find(bit) != dp.end() ? dp[bit] : inf);
		for (int j = 0; j < 26; ++j) {
			map<int, int>::iterator it = dp.find(bit ^ (1 << j));
			if (it != dp.end()) {
				opt = min(opt, it->second + 1);
			}
		}
		if (opt != inf) dp[bit] = opt;
	}
	return (bit == 0 ? 1 : dp[bit]);
}
int main() {
	string S;
	cin >> S;
	cout << solve(S) << endl;
	return 0;
}