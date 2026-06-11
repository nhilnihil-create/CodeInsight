#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	int left = stoi(s.substr(0, 2));
	int right = stoi(s.substr(2));
	string ans;
	if (left == 0) {
		if (right == 0) ans = "NA";
		else if (right <= 12) ans = "YYMM";
		else ans = "NA";
	}
	else if (left <= 12) {
		if (right == 0) ans = "MMYY";
		else if (right <= 12) ans = "AMBIGUOUS";
		else ans = "MMYY";
	}
	else {
		if (right == 0) ans = "NA";
		else if (right <= 12) ans = "YYMM";
		else ans = "NA";

	}
	cout << ans << endl;
	return 0;
}