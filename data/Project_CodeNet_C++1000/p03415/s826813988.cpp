#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	string s[5];
	for (int i = 0; i < 3; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << s[i][i];
	}
	return 0;
}