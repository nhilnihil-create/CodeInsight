#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll calc(ll x){
	if(x <= 0) return 0;
	ll res = 0;
	rep(i,40){
		ll hoge = (1LL << (i+1));
		ll foo = x / hoge;
		ll bar = x % hoge;
		ll cnt = foo * hoge / 2;
		cnt += max(bar - hoge / 2 + 1, 0LL);
		if(cnt%2 == 1) res |= (1LL << i);
	}
	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a, b;
	cin >> a >> b;
	ll ans;
	if(a == 0) ans = calc(b);
	else ans = calc(b) ^ calc(a-1);
	cout << ans << endl;
	return 0;
}
