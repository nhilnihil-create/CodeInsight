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
	int a, b; cin >> a >> b;
	if (a >= 13)cout << b << endl;
	else if (6 <= a)cout << b / 2 << endl;
	else cout << 0 << endl;
	return 0;
}

