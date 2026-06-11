#include <bits/stdc++.h>

using namespace std;

int main() {

	string n;
	cin >> n;

	int res=0;
	int ncount = 0;
	for (int i = 1; i < n.size(); i++) {
		res += 9;
		if (n[i] == '9') { ncount++; }
	}

	if (ncount != n.size() - 1) {
		cout << res + (char)(n[0]) - '0' - 1 << endl;
	}
	else {
		cout << res + (char)(n[0]) - '0' << endl;
	}
	return 0;
}