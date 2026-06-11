#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

#define endl "\n"
#define newline	cout << "\n"
#define puts(x)	cout << x << "\n"

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;


const int MN = 2E5;

#define two(x)	(1 << (x))
#define pc(x)	__builtin_popcount(x)

int h[MN], dp[two(26)];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef Home
   freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
	cin >> s;
	int n = s.length();

	h[0] = two(s[0] - 'a');
	REP(i, 1, n) {
		h[i] = h[i-1]^(two(s[i] - 'a'));
	}
	
	memset(dp, 0x7F, sizeof dp); 
	REP(i, 0, n) {
		if(pc(h[i]) <= 1) dp[h[i]] = 1;
		else {
			REP(j, 0, 26) {
				dp[h[i]] = min(dp[h[i]], dp[h[i]^two(j)]+1);
			}
		}
	}
	puts(dp[h[n-1]]);	
   return 0;
}