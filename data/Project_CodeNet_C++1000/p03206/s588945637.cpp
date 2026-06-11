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
	int d;
	cin >> d;
	switch (d) {
	case 22:
		cout << "Christmas Eve Eve Eve" << endl;
		break;
	case 23:
		cout << "Christmas Eve Eve" << endl;
		break;
	case 24:
		cout << "Christmas Eve" << endl;
		break;
	case 25:
		cout << "Christmas" << endl;
		break;
	}
}
