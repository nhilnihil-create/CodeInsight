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

	int d = BIG_NUM;
	for (int i = 0; i < s.length() - 2; i++) {

		int num = 0;
		for (int j = 0; j < 3; j++) {
			num = num * 10 + (s[i + j] - '0');
		}

		d = min(d, abs(num - 753));
	}

	cout << d << endl;
}
