#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	ll ans = 700;
	for (char c : s) {
		if (c == 'o')ans += 100;
	}
	cout << ans << endl;
}
