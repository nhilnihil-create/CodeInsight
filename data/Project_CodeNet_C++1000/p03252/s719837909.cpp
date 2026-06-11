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
#include <queue>
#include <list>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

#define for1(n) for (int i = 0 ; i < n ; i++)
#define for2(n) for (int j = 0 ; j < n ; j++)
#define for1l(n) for (ll i = 0 ; i < n ; i++)
#define for2l(n) for (ll j = 0 ; j < n ; j++)

int main() {
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int a[26] = {}, b[26] = {};
    bool y = 1;
    for1(s.length()) {
    	a[s[i] - 'a']++;
		b[t[i] - 'a']++;
        if (a[s[i] - 'a'] != b[t[i] - 'a']) {
    		cout << "No";
    		return 0;
        }
	}
    cout << "Yes";
}