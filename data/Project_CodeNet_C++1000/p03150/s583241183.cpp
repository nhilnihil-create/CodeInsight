#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	s += "#";
	for (int i = 0; i < n; i++) {
		for (int j = i; j <= n; j++) {
			string t = s.substr(0, i) + s.substr(j, n - j);
			if (t == "keyence") {
				cout << "YES" << endl;
				return 0;
			} 		
		}
	}
	cout << "NO" << endl;
	return 0;
}
