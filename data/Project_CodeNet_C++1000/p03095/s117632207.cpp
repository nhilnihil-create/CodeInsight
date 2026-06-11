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
long long co[30] = { 0 };
long long ans = 1;
int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		co[int(s[i] - 'a')]++;
	}
	for (int i = 0; i < 26; i++) {
		ans = ans * (co[i] + 1) % 1000000007;
	}
	ans--;
	if (ans < 0) {
		ans += 1000000007;
	}
	cout << ans << endl;
}
