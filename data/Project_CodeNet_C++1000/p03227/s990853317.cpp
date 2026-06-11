#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <map>
#include <utility>
#include <numeric>
#define ll long long
#define REP(i, x) for(int (i) = 0; (i) < (x); (i) ++)
#define pi 3.1415926535
const int MOD = 1000000007;
using namespace std;

int main() {
	string s;
	cin >> s;
	if (s.size() == 2) {
		cout << s << endl;
	}
	else {
		cout << s[2] << s[1] << s[0] << endl;
	}
	return 0;
}