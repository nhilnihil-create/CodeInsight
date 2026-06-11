#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>
#include <regex>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}


int main() {
	int c[3][3] = {};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c[i][j];
		}
	}
	bool ok = true;
	for (int j = 1; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			ok = ok && (c[0][0] - c[0][k] == c[j][0] - c[j][k]);
			ok = ok && (c[0][0] - c[k][0] == c[0][j] - c[k][j]);
		}
	}
	print(ok?"Yes":"No");
}