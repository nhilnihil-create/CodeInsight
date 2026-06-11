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
	int n;
	cin >> n;
	int co = 0;
	for (int i = 2; i < 55555; i++) {
		bool b = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				b = false;
			}
		}
		if (b == true) {
			if (i % 5 == 1) {
				co++;
				if (co <= n) {
					cout << i;
					if (co != n) {
						cout << " ";
					}
				}
			}
		}
	}
	cout << endl;
	return 0;
}
