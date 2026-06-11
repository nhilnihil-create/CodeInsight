#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	string s;
	cin >> s;

	int ans = 0;
	int tmp = 0;
	for (int i = 0;i < s.length();i++) {
		if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
			tmp++;
		}
		else {
			if (ans < tmp) {
				ans = tmp;
			}
			tmp = 0;
		}
	}

	if (ans < tmp) {
		ans = tmp;
	}

	cout << ans << endl;
	return 0;
}
