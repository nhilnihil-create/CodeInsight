#define _ITERATOR_DEBUG_LEVEL 1


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, n = 100, i, j, k, aa, bb;
	cin >> a >> b;
	vector<vector<bool>> x(n, vector<bool>(n, false));
	for (i = 0; i < n / 2; i++) {
		for (j = 0; j < n; j++) x[i][j] = true;
	}
	a--;
	b--;
	for (i = 0; i < b; i++) {
		aa = i / 50 * 2;
		bb = (i % 50) * 2;
		x[aa][bb] = false;
	}

	for (i = 0; i < a; i++) {
		aa = i / 50 * 2 + 55;
		bb = (i % 50) * 2;
		x[aa][bb] = true;
	}

	cout << n << " " << n << "\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (!x[i][j]) cout << "#";
			else cout << ".";
		}
		cout << "\n";
	}

	return 0;
}
