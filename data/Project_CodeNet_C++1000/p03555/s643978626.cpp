#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


int main() {
	
	string s;
	string t;
	cin >> s >> t;
	string ss = s, tt = t;
	swap(s[0], s[2]);
	swap(t[0], t[2]);
	swap(s, t);
	if (s == ss && t == tt) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}