#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	vector<char> s(4);
	rep(i, 4) {
		cin >> s[i];
	}
	int count = 0;
	rep(i, 4) {
		if (s[i] == '+') {
			count++;
		}
		if (s[i] == '-') {
			count--;
		}
	}
	cout << count << endl;
}