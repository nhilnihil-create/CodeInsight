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
int d[200020], t[200020];
int main(){
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> t[j];
	}
	sort(d, d + n);
	sort(t, t + m);
	int co = 0;
	for (int k = 0; k < n; k++) {
		if (d[k] == t[co]) {
			co++;
		}
	}
	if (co == m) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}