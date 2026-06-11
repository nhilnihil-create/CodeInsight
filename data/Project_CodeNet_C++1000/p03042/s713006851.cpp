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

	int x = 0;
	int y = 0;
	for (int i = 0; i < 2; i++) {
		x = x * 10 + (s[i] - '0');
		y = y * 10 + (s[i + 2] - '0');
	}



	if (x > 12 || x == 0) {
		if (y > 12 || y == 0) {
			cout << "NA" << endl;
		}
		else {
			cout << "YYMM" << endl;
		}
	}
	else {
		if (y > 12 || y == 0) {
			cout << "MMYY" << endl;
		}
		else {
			cout << "AMBIGUOUS" << endl;
		}




	}
}
