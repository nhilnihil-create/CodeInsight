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

	int i, j, k, a, b;
	map<int, int> ct;
	for (i = 0; i < 3; i++) {
		cin >> a >> b;
		ct[a]++;
		ct[b]++;
	}
	bool valid = true;
	for (auto p : ct) {
		if (p.second > 2) valid = false;
	}
	if (valid) cout << "YES";
	else cout << "NO";

	return 0;
}

