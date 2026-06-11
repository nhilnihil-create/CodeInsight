#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

using ll = long long;

const int Inf = 100100100;
const double EPS = 1e-9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
	int r, d, x;
	cin >> r >> d >> x;
	rep (i, 10) {
	  x = x * r - d;
	  cout << x << endl;
	}

    return 0;
}
