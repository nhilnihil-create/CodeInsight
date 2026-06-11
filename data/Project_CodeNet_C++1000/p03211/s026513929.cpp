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
	string s;
	cin >> s;
	int mn = 753;
	for (int i=0; i<s.length()-2; i++) {
		int sub = stoi(s.substr(i, 3));
		mn = min(abs(753-sub), mn);
	}
	cout << mn << endl;
}