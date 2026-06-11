#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll, ll> P;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll xor_of (ll c) {
	ll bits = 0;
	c++;
	for (ll i = 0; (1LL << i) <= c; i++) {
		ll loop = (1LL << (i + 1));
		ll d = c / loop;
		ll ones = loop / 2 * d;
		ll r = c % loop;
		ll loop2 = (1LL << i);
		if (r > loop2) {
			ones += r - loop2;
		}
		ones %= 2;
		if (ones) {
			bits |= (1LL << i);
		}
	}
	return bits;
}

int main() {
	//rep(i, 100) {
	//	ll sum = 0;
	//	rep(j, i + 1) {
	//		sum ^= j;
	//	}
	//	cout << i << "," << sum << "," << xor_of(i) << endl;
	//}

	//周期
	//0...0,1,0,1,0,1
	//1...0,0,1,1,0,0,1,1
	//2...0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1
	//3...0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,

	ll a, b;
	cin >> a >> b;
	ll xa = xor_of(a-1);
	ll xb = xor_of(b);
	cout << (xa ^ xb) << endl;
	return 0;
}
