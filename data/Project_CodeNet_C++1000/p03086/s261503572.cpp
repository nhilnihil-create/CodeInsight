#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	string str;
	int count = 0, ans = 0;
	cin >> str;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == 'A' || str[i] == 'C' || str[i] == 'G' || str[i] == 'T') {
			count++;
		}
		else {
			ans = max(ans, count);
			count = 0;
		}
	}
	ans = max(ans, count);
	cout << ans;
}
