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
	for (int i = (int)s.length() - t.length() ; i >= 0 ; i--) {
		bool y = 0;
		for (int j = 0 ; j < t.length() ; j++) if (s[j + i] != '?' && s[j + i] != t[j]) y = 1;
		if (y == 0) {
            for (int j = 0 ; j < t.length() ; j++) s[j + i] = t[j];
            for (int j = 0 ; j < s.length() ; j++) if (s[j] == '?') s[j] = 'a';
            cout << s;
            return 0;
      	}
	}
	cout << "UNRESTORABLE";
}