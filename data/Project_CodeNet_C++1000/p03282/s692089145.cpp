#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	string s; cin >> s;
	ll k; cin >> k;
	ll firstNotOne;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '1') {
			firstNotOne = i + 1;
			break;
		}
	}
	if (firstNotOne <= k) {
		cout << s[firstNotOne - 1] << endl;
	}
	else {
		cout << 1 << endl;
	}
	return 0;
}