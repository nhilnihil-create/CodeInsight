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
using ll = long long;


int main() {
	string s;
	ll k;
	cin >> s >> k;

	for(int i=0; i<min((ll)s.size(), k); i++) {
		if (s[i]!='1') {
			cout << s[i] << endl;
			return 0;
		}
	}
	cout << '1' << endl;
}