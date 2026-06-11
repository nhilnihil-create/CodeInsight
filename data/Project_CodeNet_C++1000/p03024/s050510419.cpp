#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	ll ans = 0;
	for (int i = 0; i < s.length(); i++)if (s.at(i) == 'x')ans++;
	if (ans <= 7)cout << "YES" << endl;
	else cout << "NO" << endl;
}