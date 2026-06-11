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

	string s, ans;
	cin >> s;
	int n = s.length(), i, j, k;

	if (n < 26) {
		set<char> ss;
		char ch;
		for (auto ch : s) ss.insert(ch);
		for (ch = 'a'; ch <= 'z'; ch++) {
			if (ss.find(ch) == ss.end()) {
				ans = s + ch;
				break;
			}
		}
	}
	else {
		ans = s;
		if (!next_permutation(ans.begin(), ans.end())) ans = "-1";
		else {
			set<char> ss;
			for (i = n - 1; i >= 0; i--) {
				for (auto ch : ss) {
					if (ch > s[i]) {
						ans = s.substr(0, i) + ch;
						goto outer;
					}
				}
				ss.insert(s[i]);
			}
		outer:;
		}
	}

	cout << ans << "\n";


	return 0;
}
