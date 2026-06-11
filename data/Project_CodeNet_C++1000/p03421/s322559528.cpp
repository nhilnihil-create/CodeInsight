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
	int N, A, B;
	cin >> N >> A >> B;
	
	bool ok = true;
	ok &= A + B - 1 <= N;
	ok &= N <= (ll)A * B;
	
	if (!ok) {
		puts("-1");
		return 0;
	}
	
	vector<int> ans;
	int last = 0;
	for (int i = B; i > 0; --i) ans.emplace_back(i);
	
	last = B;
	int dupc = A - 1;
	for (int i = A - 1; i >= 0; --i) {
		int diff = N - ans.size();
		int cur = min(B - 1, diff - i) + 1;
		for (int j = last + cur; j > last; --j) ans.emplace_back(j);
		last = last + cur;
	}
	
	for (int i = 0; i < ans.size() - 1; ++i) printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
	
	return 0;
}
