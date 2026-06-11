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
	cout << fixed << setprecision(12);
	int n, k;
	cin >> n >> k;
	double res = 0;
	rep (i, n) {
	  double start = i + 1, pr = 1.0;
	  while (start < k) {
		start *= 2;
		pr *= 0.5;
	  }
	  res += pr;
	}
	cout << res * (1.0 / (double)n) << endl;
	
	
    return 0;
}

