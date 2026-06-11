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
int main(){
	string s;
	cin >> s;
	string s1 = s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n - i; j++) {
			string key = s.erase(i, j);
			if (key == "keyence") {
				cout << "YES" << endl;
				return 0;
			}
			s = s1;
		}
	}
	cout << "NO" << endl;
	return 0;
}