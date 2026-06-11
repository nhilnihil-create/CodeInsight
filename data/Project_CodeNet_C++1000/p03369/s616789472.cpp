#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	ll ans = 0;
	for (int i = 0; i < 3; i++)if (s.at(i) == 'o')ans += 100;
	cout << 700 + ans << endl;
}