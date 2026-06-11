#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	vector<char> s(3);
	rep(i, 3) {
		cin >> s[i];
	}
	int a_count = 0;
	int b_count = 0;
	int c_count = 0;
	rep(i, 3) {
		if (s[i] == 'a') {a_count++;}
		if (s[i] == 'b') {b_count++;}
		if (s[i] == 'c') {c_count++;}
	}
	if (a_count > 0 && b_count > 0 && c_count > 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}