#include<bits/stdc++.h>
const int maxn = 200200;
const int mod = 998244353;
typedef long long ll;
inline ll pow(ll a,int b,ll ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline void reduce(int & x){ x += x >> 31 & mod; }
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
int n;
ll x[maxn], y[maxn];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	int flg1 = 1, flg2 = 1;
	for(int i = 1;i <= n;++i) {
		std::cin >> x[i] >> y[i];
		flg1 &= x[i] + y[i] & 1;
		flg2 &= x[i] + y[i] + 1 & 1;
	}
	if(!flg1 && !flg2) {
		std::cout << - 1 << '\n';
		return 0;
	}
	std::vector<ll> v;
	if(flg2) v.push_back(1);
	for(int i = 30;i >= 0;--i) v.push_back(1ll << i);
	std::cout << v.size() << '\n';
	for(int i : v) std::cout << i << ' ';
	std::cout << '\n';
	for(int i = 1;i <= n;++i) {
		for(ll j : v) {
			if(std::abs(x[i]) > std::abs(y[i])) {
				if(x[i] > 0) x[i] -= j, std::cout.put('R');
				else x[i] += j, std::cout.put('L');
			} else {
				if(y[i] > 0) y[i] -= j, std::cout.put('U');
				else y[i] += j, std::cout.put('D');
			}
		}
		std::cout << '\n';
	}
}
