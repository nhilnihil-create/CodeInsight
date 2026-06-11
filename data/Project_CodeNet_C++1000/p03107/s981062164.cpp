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
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	string s;
	cin >> s;
	stack<char> st;

	int res = 0;
	for (int i=0; i<s.size(); i++) {
		if (st.empty()) {
			st.push(s[i]);
			continue;
		}
		if (st.top()!=s[i]) {
			st.pop();
			res += 2;
		}
		else st.push(s[i]);
	}
	cout << res << endl;
}