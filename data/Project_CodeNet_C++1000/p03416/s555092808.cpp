#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int ans = 0;
	for (int i = A; i <= B; ++i) {
		string str = std::to_string(i);
		string str2 = str;
		reverse(str2.begin(), str2.end());
		if (str == str2) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
