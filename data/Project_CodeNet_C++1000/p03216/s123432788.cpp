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
	string S;
	cin >> N >> S;
	int Q;
	cin >> Q;
	while (Q--) {
		int K;
		scanf("%d", &K);
		
		ll ans = 0;
		ll cntm = 0, cntc = 0, cur = 0, pos = 0;
		REP(i, N) {
			while(pos < N && pos < i + K) {
				if (S[pos] == 'M') ++cntm;
				else if (S[pos] == 'C') {
					++cntc;
					cur += cntm;
				}
				++pos;
			}
			if (S[i] == 'D') ans += cur;
			else if (S[i] == 'M') {
				--cntm;
				cur -= cntc;
			}
			else if (S[i] == 'C') {
				--cntc;
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
