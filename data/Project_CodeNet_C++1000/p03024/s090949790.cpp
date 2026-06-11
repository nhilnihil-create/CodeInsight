#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
	string S; cin >> S;
	int ans = 0, no = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S.at(i) == 'o') ans++;
		else no++;
	}
	if (no >= 8) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
}