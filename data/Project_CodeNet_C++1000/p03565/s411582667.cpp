#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	set<string> st;
	string s, t;
	cin >> s >> t;

	int n = sz(s), m = sz(t);
	rep(i, 0, n) {
		string _s = s;
		bool flag = true;
		rep(j, 0, m) {
			if (i + j > n || (s[i + j] != '?' && s[i + j] != t[j])) {
				flag = false;
				break;
			}
			_s[i + j] = t[j];
		}
		if (flag) {
			rep(i, 0, n) {
				if (_s[i] == '?') _s[i] = 'a';
			}
			st.insert(_s);
		}
	}

	if (sz(st) == 0) {
		cout << "UNRESTORABLE" << endl;
	} else {
		cout << *st.begin() << endl;
	}
}