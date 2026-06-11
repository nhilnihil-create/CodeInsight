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
typedef pair<ll, ll> pll;
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int N;
string S[300];
int val[300][300];

int main() {
	cin >> N;
	REP(i, N) cin >> S[i];
	
	REP(i, N) REP(j, N) {
		int cnt = 0;
		REP(k, N) {
			if (S[i][(j + k) % N] == S[(i + k) % N][j]) cnt++;
			else break;
		}
		val[i][j] = cnt;
	}
	
	int ans = 0;
	REP(i, N) REP(j, N) {
		bool ok = true;
		REP(k, N) {
			if (val[(i + k) % N][(j + k) % N] < N - k) ok = false;
		}
		if (ok) ans++;
	}
	
	cout << ans << endl;
	
	
	return 0;
}
