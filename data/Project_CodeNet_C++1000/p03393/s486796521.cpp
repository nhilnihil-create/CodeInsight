#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = (int)s.length();
	if (n < 26) {
		for (char c = 'a'; c <= 'z'; ++c) {
			if (s.find(c) == string::npos) {
				cout << s << c << endl;
				return 0;
			}
		}
	}
	else {
		for (int i = n - 2; i >= 0; --i) {
			if (s[i] < s[i + 1]) {
				char best = s[i + 1];
				for (int j = i + 1; j < n; ++j) {
					if (s[j] > s[i]) {
						best = min(best, s[j]);
					}
				}
				s[i] = best;
				s = s.substr(0, i + 1);
				cout << s << endl;
				return 0;
			}
		}
		dunk(-1);
	}
	return 0;
}