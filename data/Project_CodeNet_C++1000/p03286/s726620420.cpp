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
	int ans[1000];
	int n;
	cin >> n;
	for (int i = 0; i < 1000; i++) {
		int a = n % -2;
		ans[i] = abs(a);
		n /= -2;
		if (a < 0) {
			n++;
		}
	}
	bool ans1 = false;
	for (int j = 1000; j >= 0; j--) {
		if (ans[j] == 1) {
			ans1 = true;
		}
		if (ans1 == true) {
			cout << ans[j];
		}
	}
	if (ans1 == false) {
		cout << "0";
	}
	cout << endl;
	return 0;
}