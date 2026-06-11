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
	vector<string> target = { 
		"KIHABAR", "KIHABR", "KIHBAR", "KIHBR",
		"AKIHABAR", "AKIHABR", "AKIHBAR", "AKIHBR",
		"KIHABARA", "KIHABRA", "KIHBARA", "KIHBRA", 
		"AKIHABARA", "AKIHABRA", "AKIHBARA", "AKIHBRA"
	};
	cin >> s;
	bool solved = false;

	for (auto ss : target) {
		if (s == ss) solved = true;
	}

	if (!solved) cout << "NO\n";
	else cout << "YES\n";

	return 0;
}
