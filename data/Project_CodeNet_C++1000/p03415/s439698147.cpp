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
using namespace std;
int main() {
	char c[3][3];
	cin >> c[0][0] >> c[0][1] >> c[0][2];
	cin >> c[1][0] >> c[1][1] >> c[1][2];
	cin >> c[2][0] >> c[2][1] >> c[2][2];
	cout << c[0][0] << c[1][1] << c[2][2] << endl;
	return 0;
}

