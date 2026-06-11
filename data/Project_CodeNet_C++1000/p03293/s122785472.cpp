#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <cassert>

using namespace std;
using ll = long long;

#define nl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trav(x) for(auto& i: x)

string s, t;
bool ans = false;

string rotate(string s) {
	char c = s[s.size() - 1];
	string x = s;
	for(int i = 1; i < s.size(); i++) {
		s[i] = x[i - 1];
	}
	s[0] = c;
	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;
	for(int i = 0; i < (int)s.size() + 100; i++) {
		if(s == t) {
			ans = true;
			break;
		} else {
			s = rotate(s);
		}
	}
	if(ans) {
		cout << "Yes" << nl;
	} else {
		cout << "No" << nl;
	}
}