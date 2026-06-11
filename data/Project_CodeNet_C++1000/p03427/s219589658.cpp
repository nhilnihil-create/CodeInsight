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
int main(){
	string s;
	cin >> s;
	int n = s.size(), ans = 0, ans1 = 0;
	for (int i = 0; i < n; i++) {
		ans1 += s[i] - '0';
	}
	ans += s[0] - '1';
	ans += (n - 1) * 9;
	if (ans < ans1) {
		cout << ans1 << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}