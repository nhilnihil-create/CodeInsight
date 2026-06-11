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

	if (n==0) cout << 0 << endl;

	string res = "";
	while(n) {
		if (n%2!=0) {
			res += "1";
			n--;
		}
		else {
			res += "0";
		}
		n /= -2;
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
}