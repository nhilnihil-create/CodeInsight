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

const ll MAX = 1e9 + 5;


int main() {
	int n; 
	cin >> n;

	if (n < 6) {
		switch (n)
		{

		case 5:
			cout << 30 << " ";
		case 4:
			cout << 20 << " ";

		case 3:
			cout << 2 << " ";
			cout << 5 << " ";
			cout << 63 << " ";
		default:
			break;
		}
		return 0;
	}
	set<int> s;
	ll sum = 0;
	int cnt = 0;
	int num = 1;
	while (cnt < n) {
		num++;
		if (num % 6 == 1 || num % 6 == 5) {
			continue;
		}
		s.insert(num);
		sum += num;
		cnt++;
	}

	
	if (sum % 6 == 2) {
		s.erase(8);
		num = (num / 6 + 1) * 6;
		s.insert(num);
	}
	if (sum % 6 == 3) {
		s.erase(9);
		num = (num / 6 + 1) * 6;
		s.insert(num);
	}

	if (sum % 6 == 5) {
		s.erase(9);
		num = ((num - 4) / 6 + 1) * 6 + 4;
		s.insert(num);
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	



}