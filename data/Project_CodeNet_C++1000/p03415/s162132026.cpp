#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	vector<char> s(9);
	rep(i, 9) {
		cin >> s[i];
	}
	cout << s[0] << s[4] << s[8] << endl;
}	