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
	string S; cin >> S;
	int N = S.size();

	bool ok = true;
	if (S[0] == '0') ok = false;
	if (S[N-1] != '0') ok =false;
	rep(i, (N-1)/2) {
		if (S[i] != S[N-i-2]) ok = false;
	}
	if (!ok) {
		cout << -1 << endl;
		return 0; 
	}

	int vto = 1;
	rep2(i, 2, N+1) {
		cout << i << " " << vto << endl;
		if (S[i-2] == '1') vto = i;
	}
	return 0;
}
