#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <functional>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)
#define llrep(i, n) for(ll i = 0; i < n; ++i)
#define llREP(i, m, n) for(ll i = m; i < n; ++i)
#define llrrep(i,n) for(ll i = n; i >= 0; --i)
#define llRREP(i, m, n) for(ll i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using pli = std::pair<long long, int>;
using plpii = std::pair<long long, std::pair<int, int>>;
using pdd = std::pair<double, double>;

using namespace std;

const long long _MOD = 1000000007;
const long long MOD = 998244353;
const int ALPHABET = 27;
const double pi = 3.14159265358979;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int ans = 0;
	int counter = s.length() - 1;
	for (int i = 0; i < counter; ++i) {
		if (s[i] != s[counter]) {
			if (s[i] == 'x') {
				++ans;
			}
			else if (s[counter] == 'x') {
				--i;
				--counter;
				++ans;
			}
			else {
				cout << "-1" << "\n";
				return 0;
			}
		}
		else {
			--counter;
		}
	}

	cout << ans << "\n";

	return 0;
}

