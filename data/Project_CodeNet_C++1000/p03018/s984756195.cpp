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
long long a[100];
int main() {
	string s;
	cin >> s;
	long long n = s.size();
	long long ans = 0, co = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'A') {
			co++;
		}
		else if (s.substr(i, 2) == "BC") {
			ans += co;
			i++;
			continue;
		}
		else {
			co = 0;
		}
	}
	cout << ans << endl;
}
