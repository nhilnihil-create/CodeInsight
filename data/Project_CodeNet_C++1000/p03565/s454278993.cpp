#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

string S, T;

bool solve(string U) {
	if (U.size() < T.size()) return false;
	for (int i = 0; i <= U.size() - T.size(); i++) {
		bool flag = false;
		for (int j = 0; j < T.size(); j++) {
			if (U[i + j] != '?' && U[i + j] != T[j]) flag = true;
		}
		if (flag == false) return true;
	}
	return false;
}

int main() {
	cin >> S >> T;
	if (solve(S) == false) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != '?') continue;
		for (int j = 0; j < 26; j++) {
			S[i] = ('a' + j);
			if (solve(S) == true) break;
		}
	}
	cout << S << endl;
	return 0;
}