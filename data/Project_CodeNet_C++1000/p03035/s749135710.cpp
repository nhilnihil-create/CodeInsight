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
	int a, b;
	cin >> a >> b;
	if (a >= 13) cout << b << endl;
	else if (a <= 5) cout << 0 << endl;
	else cout << b / 2 << endl;
	
    return 0;
}
