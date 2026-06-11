#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <tuple>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for(int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 0x3b9aca07;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s; cin >> s;

	int n = (int)s.size();
	vector<bool> ex(26);
	for(char c : s) ex[c - 'a'] = true;

	if (n < 26) {
		rep(i, 0, 26) {
			if (!ex[i]) {
				cout << s + char('a' + i) << endl;
				return 0;
			}
		}
	} else {
		rrep(i, 0, n - 1) {
			ex[s[i + 1] - 'a'] = false;
			rep(j, 0, 26) {
				if (!ex[j]) {
					char c = char(j + 'a');
					if (c > s[i]) {
						cout << s.substr(0, i) + c << endl;
						return 0;
					}
				}
			}
			ex[s[i] - 'a'] = false;

		}
		cout << -1 << endl;
	}

	return 0;
}
