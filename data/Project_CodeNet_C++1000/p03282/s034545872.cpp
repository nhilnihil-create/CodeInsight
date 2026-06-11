#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; 
	ll k;
	cin >> s >> k;

	ll firstNot1Index = -1;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] != '1') {
			firstNot1Index = i;
			break;
		}
	}

	if (firstNot1Index == -1) {
		cout << '1' << endl;
		return 0;
	}

	k--;
	if (firstNot1Index <= k) {
		cout << s[firstNot1Index] << endl;
	}
	else {
		cout << '1' << endl;
	}

	return 0;
}