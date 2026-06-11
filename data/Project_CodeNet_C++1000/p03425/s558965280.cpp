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
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int n;
	cin >> n;

	vector<vector<string> > vec(6);
	rep(i, n){
		string s;
		cin >> s;
		if (s[0]=='M') vec.at(0).push_back(s);
		else if (s[0]=='A') vec.at(1).push_back(s);
		else if (s[0]=='R') vec.at(2).push_back(s);
		else if (s[0]=='C') vec.at(3).push_back(s);
		else if (s[0]=='H') vec.at(4).push_back(s);
		else vec.at(5).push_back(s);
	}

	ll res = 0;
	for (int bit=1; bit<(1<<5); bit++) {
		vector<int> s;
		rep(i, 5) {
			if (bit & (1<<i)) s.push_back(i);
		}
		if (s.size()==3) {
			ll num = 1;
			for (int i=0; i<(int)s.size(); i++) {
				num *= vec.at(s.at(i)).size();
			}
			res += num;
		}
	}
	cout << res << endl;
}