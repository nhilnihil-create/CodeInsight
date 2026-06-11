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
	int n;
	int c[500], s[500], f[500];
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> c[i] >> s[i] >> f[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int now = 0;
		for (int j = i; j < n - 1; j++) {
			if (now <= s[j]) {
				now = s[j] + c[j];
			}
			else {
				int co1 = 0;
				for (;;) {
					co1 += f[j];
					if (now - co1 <= s[j]) {
						now = s[j] + c[j] + co1;
						break;
					}
				}
			}
		}
		cout << now << endl;
	}
	cout << "0" << endl;
	return 0;
}