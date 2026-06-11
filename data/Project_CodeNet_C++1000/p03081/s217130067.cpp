#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int N, Q;
string S;
char T[212345], D[212345];

bool check(int pos) {
	REP(i, Q) if (S[pos] == T[i]) {
		pos = pos + (D[i] == 'R' ? 1 : -1);
		if (pos < 0 || pos >= N) break;
	}
	return pos < 0;
}

int solve() {
	// [l, r) 落ちる最右を知りたい
	if (!check(0)) return -1;
	
	int l = 0, r = N;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (check(m)) l = m;
		else r = m;
	}
	return l;
}

int main() {
	cin >> N >> Q;
	cin >> S;
	
	REP(i, Q) {
		string t, d;
		cin >> t >> d;
		T[i] = t[0];
		D[i] = d[0];
	}
	
	int p = solve();
	reverse(ALL(S));
	REP(i, Q) D[i] = (D[i] == 'R' ? 'L' : 'R');
	int q = N - solve() - 1;
	
	int ans = q - p - 1; // 必ずp < q, 反対側で先に落ちる場合落ちないと判定されるため
	cout << ans << endl;
	
	return 0;
}
