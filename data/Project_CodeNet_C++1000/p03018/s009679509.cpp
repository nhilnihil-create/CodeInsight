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
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const ll MAX = 1e9 + 5;

int main() {
	string s;
	cin >> s;
	int sl = s.length();
	ll cnt = 0;
	string t;
	for (int i = 0; i <sl-1; i++) {
		if (s[i] == 'A') {
			t += '0';
		}
		else if (s[i] == 'B' && s[i + 1] == 'C') {
			t += '1';
			i++;
		}
		else {
			
			int tl = t.length();
			int p = 0;
			for (int j = 0; j < tl; j++) {
				if (t[j] == '1') {
					cnt += j - p;
					p++;
				}
			}

			t = string();

		}

	}

	int tl = t.length();
	int p = 0;
	for (int j = 0; j < tl; j++) {
		if (t[j] == '1') {
			cnt += j - p;
			p++;
		}
	}

	t = string();
	//cout << s << endl;
	cout << cnt << endl;
}