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
	long long k, a, b;
	cin >> k >> a >> b;
	k++;
	long long co = 0;
	if (a + 2 >= b) {
		cout << k << endl;
	}
	else {
		co += a;
		k -= a;
		co += k / 2 * b - a * (k / 2);
		co += k % 2;
		cout << co << endl;
	}
	return 0;
}