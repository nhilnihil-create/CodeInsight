#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	char x, y;
	cin >> x >> y;

	if (x == y) {
		cout << '=' << endl;
	} else {
		cout << (x < y ? '<' : '>') << endl;
	}
	return 0;
}
