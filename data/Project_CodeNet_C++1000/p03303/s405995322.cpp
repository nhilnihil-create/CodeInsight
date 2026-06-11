#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	int W;
	cin >> S;
	cin >> W;
	string ans = "";
	for (int i=0; i < S.length(); i += W) {
		ans += S.at(i);
	}

	cout << ans << endl;
}