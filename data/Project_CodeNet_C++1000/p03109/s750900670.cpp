#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;



int main() {
	string s;
	cin >> s;
	int y = 0;
	for (int i = 0; i < 4; i++) {
		y = y * 10 + (s[i] - '0');
	}

	int m = 0;
	for (int i = 5; i < 7; i++) {
		m = m * 10 + (s[i] - '0');
	}

	int d	 = 0;
	for (int i = 8; i < 19; i++) {
		d = d * 10 + (s[i] - '0');
	}

	bool isHeisei;
	if (y != 2019) {
		isHeisei = y < 2019;
	}
	else {
		if (m != 4) {
			isHeisei = m < 4;
		}
		else {
			isHeisei = d <= 30;
		}
	}

	if (isHeisei) {
		cout << "Heisei" << endl;
	}
	else {
		cout << "TBD" << endl;
	}
}
