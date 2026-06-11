#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

using ll = long long;

const int Inf = 1e9;
const double EPS = 1e-9;

int main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	string s;
	cin >> n >> k >> s;
	rep(i, n) {
	  if (i == k - 1) cout << char(s[i] - 'A' + 'a');
	  else cout << s[i];
	}
	cout << endl;
	
    return 0;
}

