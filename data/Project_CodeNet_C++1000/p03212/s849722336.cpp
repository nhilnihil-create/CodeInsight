#include <iostream>
#include <string>
using namespace std;

const string decimals = "753";

bool check(string& s, long n) {
	if (stoll(s) > n) {
		return false;
	}
	for (char c : decimals) {
		if (s.find(c) == string::npos) {
			return false;
		}
	}
	return true;
}

int dfs(string s, long n) {
	int res = 0;
	if (!s.empty()) {
		if (check(s, n)) {
			++res;
		} else if (stoll(s) > n) {
			return 0;
		}
	}
	for (char next : decimals) {
		res += dfs(s + next, n);
	}
	return res;
}

int solve(long n) {
	return dfs("", n);
}

int main() {
	long n;
	cin >> n;

	cout << solve(n) << endl;

	return 0;
}