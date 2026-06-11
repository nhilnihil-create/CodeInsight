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
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

//typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
const double EPS = 1e-7;
const double MAX = 1000 + 5;



int main() {
	string s;
	cin >> s;
	int n = s.length();

	if (s[0] == '0' || s[n - 1] == '1') {
		cout << -1 << endl;
		return 0;
	}
	

	for (int i = 0; i <= (n-1)/2; i++) {
		if (s[i] !=  s[n-2-i]) {
			cout << -1 << endl;
			return 0;
		}
	}

	s[n - 1] = '1';
	int r = 0;
	
	for (int i = 0; i < n-1; i++) {
		while (r <= i || s[r] == '0') {
			r++;
		}

		cout << i + 1 << " " << r + 1<< endl;
	}
}