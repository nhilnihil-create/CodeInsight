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


const int MAX = 100005;


int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		s[i] += s[i];

	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		bool isGood = true;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (j == k) {
					continue;
				}

				isGood = isGood && (s[j][i + k] == s[k][i + j]);
			}
		}

		if (isGood) {
			ans += n;
		}
	}
	cout << ans << endl;
}