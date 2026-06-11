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
	ll N; cin >> N;
	V A(N);
	rep(i, N) cin >> A[i];

	Vll S(N+1);
	rep(i, N) S[i+1] = S[i] + A[i];

	auto div = [&] (int i, int j) {
		ll th = S[i] + (S[j] - S[i])/2;
		int r = upper_bound(S.begin()+i, S.begin()+j, th) - S.begin();
		int l = r - 1;
		if (r == j) r--;
		int al = abs((S[j] - S[l]) - (S[l] - S[i]));
		int ar = abs((S[j] - S[r]) - (S[r] - S[i]));
		if (al < ar) return Pll(S[j] - S[l], S[l] - S[i]);
		else         return Pll(S[j] - S[r], S[r] - S[i]);
	};

	ll cmin = INFll;
	rep2(k, 2, N-1) {
		Pll p1 = div(0, k);
		Pll p2 = div(k, N);
		Pll mima = minmax({p1.first, p1.second, p2.first, p2.second});
		cmin = min(cmin, abs(mima.first - mima.second));
	}

	cout << cmin << endl;
	return 0;
}
