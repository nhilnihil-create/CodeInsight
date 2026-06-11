#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

template<typename T>
vector<T> gen_v(size_t a) { return vector<T>(a); }
template<typename T, typename ...Ts>
auto gen_v(size_t a, Ts... ts) { return vector<decltype(gen_v<T>(ts...))>(a, gen_v<T>(ts...)); }
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) { for (auto &e : t) fill_v(e, v); }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W, N; cin >> H >> W >> N;
	int sr, sc; cin >> sr >> sc;
	sr--, sc--;
	string S, T; cin >> S >> T;

	bool yes = true;
	{
		int l = 0, r = W;
		rrep(i, 0, N) {
			dump(l, r);
			if (T[i] == 'L')r = min(W, r + 1);
			if (T[i] == 'R')l = max(0LL, l - 1);
			if (S[i] == 'L')l++;
			if (S[i] == 'R')r--;
			if (l == r)yes = false;
		}
		dump(l, r);
		yes &= (l <= sc && sc < r);
	}
	{
		int l = 0, r = H;
		rrep(i, 0, N) {
			dump(l, r);
			if (T[i] == 'U')r = min(H, r + 1);
			if (T[i] == 'D')l = max(0LL, l - 1); 
			if (S[i] == 'U')l++;
			if (S[i] == 'D')r--;
			if (l == r)yes = false;
		}
		dump(l, r);
		yes &= (l <= sr && sr < r);
	}

	cout << (yes ? "YES" : "NO") << endl;


	return 0;
}