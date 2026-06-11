#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	vector<char> s(10);
	rep(i, 10) {
		cin >> s[i];
	}
	s[3] = '8';
	rep(i, 10) {
		cout << s[i];
	}
	cout << endl;
}	