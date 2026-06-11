#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
ll mod = 1000000007LL;

vector<bool> check_used(string& s) {
	vector<bool> used(26, false);

	for(char c : s) {
		used[c - 'a'] = true;
	}
	return used;
}

char first_not_used(vector<bool> & used) {
	rep(i, 26) {
		if (used[i] == false) {
			return i + 'a';
		}
	}
	return -1;
}

int main() {
	string s;
	cin >> s;
	if (s == "zyxwvutsrqponmlkjihgfedcba") {
		cout << -1 << endl;
		return 0;
	}

	vector<bool> used = check_used(s);
	char first = first_not_used(used);

	if (s.size() < 26) {
		cout << s << first << endl;
		return 0;
	}
	
	for (int i = s.size() - 1; i >= 0; i--) {
		// zyxwvutsrqponmlkjihgfedcab
		// zyxwvutsrqponmlkjihgfedca


		if (s[i - 1] < s[i]) {
			used[s[i] - 'a'] = false;
			s.pop_back();

			for (int j = s[i - 1] - 'a'; j < 26; j++) {
				if (!used[j]) {
					s[i - 1] = j + 'a';
					cout << s << endl;
					return 0;
				}
			}
 			continue;
 		}
		used[s[i] - 'a'] = false;
		s.pop_back();
	}
	
	return 0;
}
