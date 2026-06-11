#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	string s;
	cin >> s;
	int l = 0, r = s.size() - 1, co = 0;
	for (;;) {
		if (l == r || r == l - 1) {
			break;
		}
		if (s[l] == s[r]) {
			l++;
			r--;
			continue;
		}
		else if (s[l] == 'x') {
			co++;
			l++;
			continue;
		}
		else if (s[r] == 'x') {
			co++;
			r--;
			continue;
		}
		else {
			cout << "-1" << endl;
			return 0;
		}
		cout << l << " " << r << endl;
	}
	cout << co << endl;
}
