#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define ALL(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = int(1e9)+10;
const ll INFll = ll(1e18)+10;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;

int main() {
	int L; cin >> L;
	
	int N = 0;
	int x = L;
	while (x > 0) {
		N++;
		x /= 2;
	}

	int M = 2*(N-1) + __builtin_popcount(L) - 1;
	cout << N << " " << M << endl;

	rep(i, N-1) {
		cout << (i+1) << " " << (i+2) << " " << 0 << endl;
		cout << (i+1) << " " << (i+2) << " " << (1<<(N-2-i)) << endl;
	}

	int w = 1<<(N-1);
	rep(i, N-1) {
		if (L % 2) {
			cout << 1 << " " << (N-i) << " " << w << endl;
			w += 1<<i;
		}
		L /= 2;
	}
	
	return 0;
}
