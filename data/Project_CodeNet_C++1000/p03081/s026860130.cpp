#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <limits.h>
#include <math.h>

using namespace std;

int n, q;
string s;

bool check(int &x, vector<pair<char, char>> &da, int po) {
	char no = s[po];
	for (int i = 0;i < q;i++) {
		if (no == da[i].first) {
			if (da[i].second == 'L') {
				po--;
			}
			else {
				po++;
			}
		}
		if (po == x) {
			return false;
		}
		if (po == n - 1 - x) {
			return true;
		}
		no = s[po];
	}
	return true;
}

int nibutan(int x, int le, int ri, vector<pair<char, char>> &da) {
	if (ri - le == 1) {
		return le;
	}
	if (check(x, da, (ri + le) / 2) ^ (x == -1)) {
		le = (ri + le) / 2;
	}
	else {
		ri = (ri + le) / 2;
	}
	return nibutan(x, le, ri, da);
}

int main() {
	cin >> n >> q >> s;
	vector<pair<char, char>> da(q);
	for (int i = 0;i < q;i++) {
		cin >> da[i].first >> da[i].second;
	}
	cout << nibutan(n, -1, n, da) - nibutan(-1, -1, n, da) << endl;
}