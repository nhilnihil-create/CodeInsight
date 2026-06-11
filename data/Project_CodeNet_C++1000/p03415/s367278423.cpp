#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	string s[3];
	for (int i = 0; i < 9; i++) {
		cin >> s[i];
	}
	printf("%c%c%c\n", s[0][0], s[1][1], s[2][2]);

	return 0;
}
