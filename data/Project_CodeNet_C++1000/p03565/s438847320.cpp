#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = j; i < n; ++i)
#define rrep(i, j, n) for(int i = n - 1; j <= i; --i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;



int main() {
	string s, t;
	cin >> s >> t;
	int n = (int)s.size();
	int m = (int)t.size();
	rrep(i, 0, n - m + 1) {
		bool ok = true;
		rep(j, 0, m) {
			if (s[i + j] != '?' && s[i + j] != t[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			rep(j, 0, m) {
				if (s[i + j] == '?') s[i + j] = t[j];
			}
			rep(i, 0, n) if (s[i] == '?') s[i] = 'a';
			cout << s;
			return 0;
		}
	}
	cout << "UNRESTORABLE";
	return 0;
}