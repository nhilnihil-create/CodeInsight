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

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll A, B, C, D;
		cin >> A >> B >> C >> D;
		puts([&] {
			if (A < B || B > D) return false;
			if (C >= B) return true;
			ll st = (A - B) % B;
			if (C < st) return false;
			ll g = gcd(B, D);
			ll mn = (st + (C + 1 - st + g - 1) / g * g) % B;
			return mn <= C;
		}() ? "Yes": "No");
	}
	return 0;
}
