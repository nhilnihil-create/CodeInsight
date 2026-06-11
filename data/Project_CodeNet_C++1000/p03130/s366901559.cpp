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
int co[4] = { 0 };
int main(){
	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		co[a - 1]++;
		co[b - 1]++;
	}
	sort(co, co + 4);
	if (co[0] == 1 && co[1] == 1 && co[2] == 2 && co[3] == 2) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}