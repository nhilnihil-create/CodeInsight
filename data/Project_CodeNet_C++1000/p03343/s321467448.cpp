#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
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
	int N, K, Q;
	cin >> N >> K >> Q;
	
	vector<int> A(N);
	REP(i, N) scanf("%d", A.begin() + i);
	
	int ans = INF;
	vector<int> ord(N);
	REP(i, N) ord[i] = i;
	sort(ALL(ord), [&](int x, int y) {
		return A[x] < A[y];
	});
	
	for (int i : ord) {
		int p = 0;
		vector<int> v;
		while (p < N) {
			if (A[i] > A[p]) { p++; continue; }
			int cnt = 0;
			vector<int> cur;
			while (p + cnt < N && A[i] <= A[p + cnt]) {
				cur.emplace_back(A[p + cnt]);
				cnt++;
			}
			if (cnt >= K) {
				sort(ALL(cur));
				REP(j, cur.size() - K + 1) v.emplace_back(cur[j]);
			}
			p += cnt;
		}
		if (v.size() < Q) break;
		sort(ALL(v));
		chmin(ans, v[Q - 1] - v[0]);
	}
	
	cout << ans << endl;
	
// REP(i, N) printf("%d %d\n", A[ord[i]], ord[i]);
	
	return 0;
}
