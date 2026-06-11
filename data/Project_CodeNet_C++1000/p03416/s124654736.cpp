#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int A, B;
	cin >> A >> B;

	int ans = 0;
	for (int i = A; i <= B; ++i) {
		string str = to_string(i);
		bool f = true;
		for (int j = 0; j < str.size() / 2; ++j) {
			if (str[j] != str[str.size() - 1 - j]) {
				f = false;
				break;
			}
		}
		if (f) {
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
