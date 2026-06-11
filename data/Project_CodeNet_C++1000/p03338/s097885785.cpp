#include <bits/stdc++.h>

using namespace std;

string s;
bool exist(char c, int l, int r) {
	for (int i = l; i <= r; i++) {
		if (c == s[i]) {
			return true;
		}
	}
	return false;
}

int main() {
    int n;
    cin >> n >> s;
    int res = 0;
    for (int i = 0; i < n; i++) {
		int sum = 0;
		for (char c = 'a'; c <= 'z'; c++) {
			sum += exist(c, 0, i) & exist(c, i + 1, n - 1);
		}
		res = max(res, sum);
	}
	cout << res;
    return 0;
}
