#include <iostream>
#include <string>
#include <algorithm>
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
	char x, y;
	cin >> x >> y;
	if (x < y) {
		cout << "<" << endl;
	}
	else if (x == y) {
		cout << "=" << endl;
	}
	else {
		cout << ">" << endl;
	}
}