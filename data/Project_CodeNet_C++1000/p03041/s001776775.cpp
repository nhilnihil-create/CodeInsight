#include <bits/stdc++.h>

using namespace std;

int len, k;
string s;

int main () {
	cin >> len >> k >> s;
	s[k - 1] = char (s[k - 1] + 32);
	cout << s << endl;
	return 0;
}
