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
	string s;
	cin >> s;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					string co = "";
					if (i == 1) {
						co += "A";
					}
					co += "KIH";
					if (j == 1) {
						co += "A";
					}
					co += "B";
					if (k == 1) {
						co += "A";
					}
					co += "R";
					if (l == 1) {
						co += "A";
					}
					if (co == s) {
						cout << "YES" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
