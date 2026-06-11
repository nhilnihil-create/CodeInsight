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
	int s;
	set<int> se;
	cin >> s;
	int cnt = 1;
	while (se.find(s) ==se.end()) {
		se.insert(s);
		if (s % 2 == 0) {
			s /= 2;
		}
		else {
			s = s * 3 + 1;
		}
		cnt++;
		
	}

	cout << cnt << endl;
}
