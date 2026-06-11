#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
	string s;
	cin >> s;
	int result = 700;
	rep(i, 3) {
		if (s.at(i) == 'o') {
			result += 100;
		}
	}
	cout << result << endl;
}
