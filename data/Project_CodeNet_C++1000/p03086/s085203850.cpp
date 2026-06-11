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

	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 1; j + i <= s.length(); j++) {
			string t = s.substr(i, j);
			//cout << t << endl;
			bool isACGT = true;
			for (int k = 0; k < t.length(); k++) {
				switch (t[k])
				{
				case 'A':
				case 'T':
				case 'G':
				case 'C':

					break;
				default:
					isACGT = false;
					break;
				}

				
			}

			if (isACGT) {
				ans = max(ans, j);
			}
		}
	}
	cout << ans << endl;
}
