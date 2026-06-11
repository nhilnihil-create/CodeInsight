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
	vector<int> A(N);
	REP(i, N) scanf("%d", A.begin() + i);
	sort(ALL(A));
	
	int ans = 0;
	set<pii> ss;
	REP(i, N) ss.insert(pii(A[i], i));
	for (int i = N - 1; i >= 0; i--) {
		if (ss.find(pii(A[i], i)) == ss.end()) continue;
		int b;
		for (int j = 29; j >= 0; j--) if (A[i] >> j & 1) {
			b = (1<<j+1) - A[i];
			break;
		}
		
		auto it = ss.lower_bound(pii(b, -1));
		if (it == ss.end() || it->fi != b || it->se == i) continue;
		ss.erase(pii(A[i], i));
		ss.erase(it);
		ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}


