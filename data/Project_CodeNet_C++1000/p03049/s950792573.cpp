#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

int getABcnt(string s) {
	int ans = 0;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == 'A' && s[i + 1] == 'B') ans++;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	string s[10000];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int ans = 0;
	int startBEndA = 0;
	int startB = 0;
	int endA = 0;
	for (int i = 0; i < n; i++) {
		ans += getABcnt(s[i]);
		int l = s[i].length();
		if (s[i][0] == 'B' && s[i][l - 1] == 'A') startBEndA++;
		if (s[i][0] == 'B' && s[i][l - 1] != 'A') startB++;
		if (s[i][0] != 'B' && s[i][l - 1] == 'A') endA++;
	}
	if (startBEndA > 0) {
		ans += startBEndA - 1;
		if (startB > 0 || endA > 0) {
			startB++;
			endA++;
		}
	}
	ans += min(startB, endA);
	cout << ans << endl;
}