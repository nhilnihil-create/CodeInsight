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

int query(int x) {
	cout << x << "\n";
	cout.flush();

	string s;
	cin >> s;
	if (s == "Male") return 1;
	if (s == "Female") return 2;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l, r, m, i, j, k;
	cin >> n;
	vector<int> a(n + 1, -1);

	a[0] = query(0);
	a[n] = a[0];

	if (a[0] == 0) return 0;

	l = 0; r = n;
	while (l != r) {
		m = (l + r + 1) / 2;
		a[m] = query(m);
		if (a[m] == 0) return 0;

		if (((m - l) % 2 == 0) && (a[l] != a[m]) && (r != m)) r = m;
		else if (((m - l) % 2 == 1) && (a[l] == a[m]) && (r != m)) r = m;
		else l = m;
	}
	   
	return 0;
}


