#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'R')ans++;
		else ans--;
	}
	if (ans > 0)cout << "Yes" << endl;
	else cout << "No" << endl;

}