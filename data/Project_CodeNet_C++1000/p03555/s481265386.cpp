#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string c[2];
	for (int i = 0; i < 2; i++) {
		cin >> c[i];
	}
	string ans = "YES";
	for (int i = 0; i < 3; i++) {
		if (c[0][i] != c[1][2 - i]) ans = "NO";
	}
	cout << ans << "\n";
	return 0;
}
