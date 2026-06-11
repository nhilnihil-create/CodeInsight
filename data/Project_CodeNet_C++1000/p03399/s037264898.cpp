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
	int a, b, c, d;
	int e, f;
	cin >> a >> b >> c >> d;
	if (a > b) {
		e = b;
	}
	else {
		e = a;
	}
	if (c > d) {
		f = d;
	}
	else {
		f = c;
	}
	cout << e + f << endl;
	return 0;
}