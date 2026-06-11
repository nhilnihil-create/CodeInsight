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

	string s;
	cin >> s;

	int n, i, j, k, ct = 0;
	for (auto ch : s) {
		if (ch == 'o') ct++;
	}
	ct += (15 - s.length());

	if (ct >= 8) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}

