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
	int H, W, N;
	int sr, sc;
	string S, T;
	cin >> H >> W >> N >> sr >> sc >> S >> T;
	--sr; --sc;
	
	map<char, int> mm;
	{
		string s = "LRUD";
		REP(i, s.size()) mm[s[i]] = i;
	}
	
	bool ok = true;
	REP(dir, 2) {
		vector<pii> liv(N);
		int mn = 0, mx = dir == 0 ? W - 1 : H - 1;
		int l = mn, r = mx;
		
		for (int i = liv.size() - 1; i >= 0; --i) {
			int d = mm[T[i]];
			if (dir == 1 ^ d < 2) {
				int p = d & 1 ? 1 : -1;
				l = min(l, max(l - p, mn));
				r = max(r, min(r - p, mx));
			}
			d = mm[S[i]];
			ok &= l <= r;
			if (dir == 1 ^ d < 2) {
				int p = d & 1 ? 1 : -1;
				l = max(l, l - p);
				r = min(r, r - p);
			}
			ok &= l <= r;
		}
		
		int cx = dir == 0 ? sc : sr;
		ok &= l <= cx && cx <= r;
	}
	
	puts([&] {
		return ok;
	}() ? "YES": "NO");
	return 0;
}
