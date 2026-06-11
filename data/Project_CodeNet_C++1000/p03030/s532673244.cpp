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
	int n;
	cin >> n;
	vector<tuple<string, int, int>> r(n);
	for (int i = 0; i < n; i++) {
		string s;
		int p;
		cin >> s >> p;
		r[i] = make_tuple(s, -p, i + 1);
	}

	sort(r.begin(), r.end());
	for (int i = 0; i < n; i++) {
		cout << get<2>(r[i]) << endl;
	}
}
