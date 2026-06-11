#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

char grid[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	for (int i = 0; i < 100; i++) {
		char c = (i < 50)? '#' : '.';
		for (int j = 0; j < 100; j++) grid[i][j] = c;
	}

	for (int i = 0; i < 49 && a > 1; i += 2) {
		for (int j = 0; j < 100 && a > 1; j += 2) {
			grid[i][j] = '.';
			a--;
		}
	}
	for (int i = 51; i < 100 && b > 1; i += 2) {
		for (int j = 0; j < 100 && b > 1; j += 2) {
			grid[i][j] = '#';
			b--;
		}
	}

	cout << "100 100\n";
	for (int i = 0; i < 100; i++) cout << grid[i] << "\n";
}
