#include <bits/stdc++.h>
using namespace std;
int main() {
	int64_t n;
	cin >> n;
	n++;
	vector<int> digit(0);
	while (n!=0) {
		digit.push_back(n % 10);
		n = (n - (n % 10)) / 10;

	}
	reverse(digit.begin(), digit.end());
	int ans = digit.at(0) - 1 + (digit.size() - 1) * 9;
	cout << ans << endl;
}