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
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	string S, T;
	cin >> S >> T;

	for (int i=0; i<S.size(); i++) {
		string test = "";
		rep(j, S.size()) {
			int idx = (j + i)%S.size();
			test += S[idx];
		}
		if (test == T) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}