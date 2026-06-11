#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	vector<char> c(6);
	rep(i, 6) {
		cin >> c[i];
	}
	if (c[0] == c[5] && c[1] == c[4] && c[2] == c[3]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	} 
}