#include<bits/stdc++.h>
using namespace std;

int n, m;
char s[100010];

int main() {
	cin >> (s + 1);
	n = strlen(s + 1);
	if (s[1] == '0' || s[n] == '1') {
		puts("-1");
		return 0;
	}
	for (int i = 1; i < n ; i++) {
		if (s[i] != s[n - i]) {
			puts("-1");
			return 0;
		}
	}
	m = 1;
	for (int i = 1; i < n; i++) {
		cout << i + 1 << " " << m << endl;
		if (s[i] == '1') m = i + 1;
	}
	return 0;
}