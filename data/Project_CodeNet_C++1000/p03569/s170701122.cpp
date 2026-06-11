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
	int n = s.length(), i, j, k, a = 0, b = n - 1, ans = 0;
	bool valid = true;
	while (a < b) {
		if (s[a] == s[b]) a++, b--;
		else {
			if (s[a] == 'x') ans++, a++;
			else if (s[b] == 'x') ans++, b--;
			else {
				valid = false;
				break;
			}
		}
	}

	if (!valid) ans = -1;
	cout << ans << "\n";

	return 0;
}

