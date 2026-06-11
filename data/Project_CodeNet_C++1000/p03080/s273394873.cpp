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

	int n, c = 0;
	string s;
	cin >> n >> s;
	for (auto ch : s) {
		if (ch == 'R') c++;
	}

	if (c > n - c) cout << "Yes\n";
	else cout << "No\n";


	return 0;
}

