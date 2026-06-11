#include <bits/stdc++.h>
#define LL long long

using namespace std;

const LL mod = 1e9 + 9;
const LL base = 29;

map<pair<LL, LL>, LL> get(string s) {
	int sz = s.size();
	map<pair<LL, LL>, LL> res;
	for(int mask = 0; mask < (1 << sz); mask++) {
		LL h1 = 0, h2 = 0;
		LL p = 1;
		for(int b = 0; b < sz; b++) {
			if(mask & (1 << b)) {
				h1 += p * (s[b] - 'a' + 1) % mod;
				p = p * base % mod;
			}
		}
		p = 1;
		for(int b = sz - 1; b >= 0; b--) {
			if((mask & (1 << b)) == 0) {
				h2 += p * (s[b] - 'a' + 1) % mod;
				p = p * base % mod;
			}
		}
		h1 %= mod, h2 %= mod;
		res[make_pair(h1, h2)]++;
	}
	return res;
}

int main() {
	string s;
	int n;
	cin >> n;
	cin >> s;
	map<pair<LL, LL>, LL> A = get(s.substr(0, s.size() / 2));
	string bb = s.substr(s.size() / 2);
	reverse(bb.begin(), bb.end());
	map<pair<LL, LL>, LL> B = get(bb);
	LL ans = 0;
	for(auto &xx: A) {
		ans += B[xx.first] * xx.second;
	}
	cout << ans << endl;
	return 0;
}
