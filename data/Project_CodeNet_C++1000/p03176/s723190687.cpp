#include<bits/stdc++.h>
#pragma GCC optimize "trapv"
#warning "Running on trapv"
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define REP(n) for(int i = 0; i < n; i++)
#define all(p) p.begin(), p.end()
#define count_1(p) __builtin_popcountll(p)
#define count_0(p) __builtin_ctzll(p)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
template<class X=int>inline X min(X a,X b,X c){return min(min(a,b),c);}
template<class X=int>inline X min(X a,X b,X c,X d){return min(min(a,b,c),d);}
template<class X=int>inline X max(X a,X b,X c){return max(max(a,b),c);}
template<class X=int>inline X max(X a,X b,X c,X d){return max(max(a,b,c),d);}
template<class X=int>inline X mid(X s,X e){return (s+(e-s)/2);}
template<class X=int>inline X len(X s,X e){return (e-s+1);}
const int MOD = 1e9 + 7;
const int oo = 987654321;
const ll OO = 118;
const bool TESTCASES = 0;
const bool CODEJAM = 0;

struct SG {
	vector<ll> T;
	int n;
	SG(int n) {
		this->n = n;
		T.assign(2*n, 0);
	}

	void update(int p, ll v) {
		for(p += n; p > 0; p>>=1) T[p] = max(T[p], v);
	}

	ll get(int l, int r) {
		ll ret = 0;
		for(l += n, r += n + 1; l < r; l>>=1, r>>=1) {
			if(l & 1) ret = max(ret, T[l++]);
			if(r & 1) ret = max(ret, T[--r]);
		}
		return ret;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> A(n), H(n);
    vector<ll> dp(n + 1);
	REP(n) cin >> H[i];
	REP(n) cin >> A[i];
	ll ans = 0;
	SG sg(n + 1);
	for(int i = 1; i <= n; i++) {
		dp[i] = sg.get(1, H[i - 1] - 1) + A[i - 1];
		sg.update(H[i - 1], dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
}

signed main() {
	clock_t start = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 1;
	if(TESTCASES) cin >> T;
	for(int t = 1; t <= T; t++) {
		if(CODEJAM) cout << "Case #" << t << ": ";
		solve();
	}
	cerr << (double)(clock() - start)/CLOCKS_PER_SEC << "\n";
	return 0;
}
