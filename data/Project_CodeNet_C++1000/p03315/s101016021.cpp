#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	ll ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == '+')ans++;
		else ans--;
	}
	cout << ans << endl;
}