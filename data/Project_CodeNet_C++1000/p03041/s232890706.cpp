#include "bits/stdc++.h"

//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

//#define int long long
#define ll long long

ll INF = (1LL << 60);
int mod = 998244353;
using P = pair<ll, ll>;

signed main() {
	int n, k; cin >> n >> k; k--;
	string s; cin >> s;
	int tmp = s[k] - 'A';
	s[k] = (char)('a' + tmp);
	cout << s << endl;
	return 0;
}

