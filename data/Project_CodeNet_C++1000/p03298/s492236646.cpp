#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	
	map<pair<string, string>, int> mm;
	REP(i, 1 << N) {
		string a, b;
		REP(j, N) {
			if (i >> j & 1) a += S[j + N];
			else b += S[j + N];
		}
		++mm[make_pair(a, b)];
	}
	
	ll ans = 0;
	REP(i, 1 << N) {
		string a, b;
		REP(j, N) {
			if (i >> j & 1) a += S[j];
			else b += S[j];
		}
		
		reverse(ALL(b));
		reverse(ALL(a));
		ans += mm[make_pair(b, a)];
	}
	
	cout << ans << endl;
	return 0;
}
