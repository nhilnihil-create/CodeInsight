#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    if (s[0] == t[0] && s.length() < t.length()) {
    	cout << "Yes";
    	return 0;
	}
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
	for (int i = 0 ; i < min(s.length(), t.length()) ; i++) {
		if (s[i] < t[i]) {
			cout << "Yes";
			return 0;
		}
	}
	reverse(t.begin(), t.end());
	for (int i = 0 ; i < min(s.length(), t.length()) ; i++) {
		if (s[i] < t[i]) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}