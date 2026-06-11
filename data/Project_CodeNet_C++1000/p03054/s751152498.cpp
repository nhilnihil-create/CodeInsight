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
	
	int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
	map<char, int> mm;
	{
		string s = "LRUD";
		REP(i, s.size()) mm[s[i]] = i;
	}
	auto isinmap = [&](int cy, int cx) { return 0 <= cy && cy < H && cx >= 0 && cx < W; };
	
	bool ok = true;
	REP(dir, 4) { // 落とす方向
		int y = sr, x = sc;
		int ld = dir ^ 1; // 残る方向
		
		bool leave = true;
		REP(i, N) {
			int d = mm[S[i]];
			if (d == dir) {
				x += dx[d];
				y += dy[d];
			}
			leave &= isinmap(y, x);
			
			d = mm[T[i]];
			if (d == ld) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (isinmap(ny, nx)) {
					x = nx;
					y = ny;
				}
			}
		}
		if (!leave) ok = false;
	}
	
	puts([&] {
		return ok;
	}() ? "YES": "NO");
	
	return 0;
}
