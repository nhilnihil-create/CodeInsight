#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	ll ans = 0;
	for (char c : s) {
		if (c == '2')++ans;
	}
	cout << ans << endl;
}
