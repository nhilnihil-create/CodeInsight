#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	string s, t;
	cin >> s >> t;

	set<char> A[300], B[300];
	rep(i, s.size()) {
		A[s[i]].insert(t[i]);
		B[t[i]].insert(s[i]);
	}
	string ans = "Yes";
	rep(i, 300) {
		if (A[i].size()>1) {
			ans = "No";
		}
		if (B[i].size()>1){
			ans = "No";
		}
	}
	cout << ans << endl;
}