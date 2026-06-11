#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin,(a).rend()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b, c, d; string s;
	cin >> n >> a >> b >> c >> d >> s;
	a--; b--; c--; d--;
	s = "#" + s;
	for (int i = a + 1; i < c + 1; ++i) {
		if (s[i] == '#' && s[i] == s[i + 1]) {
			puts("No");
			return 0;
		}
	}
	for (int i = b + 1; i < d + 1; ++i) {
		if (s[i] == '#' && s[i] == s[i + 1]) {
			puts("No");
			return 0;
		}
	}
	if (c < d) {
		puts("Yes");
	}
	else {
		bool elf = false;
		for (int i = b; i < d + 1; ++i) {
			if (s.substr(i, 3) == "...") elf = true;
		}
		puts(elf ? "Yes" : "No");
	}


	return 0;
}