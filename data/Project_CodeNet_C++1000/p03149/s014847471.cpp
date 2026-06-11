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
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a, a + 4);
	if (a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
