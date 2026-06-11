#include <bits/stdc++.h>
#define trav(a, b) for(auto& a: b
#define all(a) a.begin(), a.end()
#define gottagofast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;
								
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map<char, int> mp;
	mp['M'] = 0;
	mp['A'] = 1;
	mp['R'] = 2;
	mp['C'] = 3;
	mp['H'] = 4;
	vector<int> cnt(6, 0);
	int n;
	cin >> n;
	while(n--) {
		string s; cin >> s;
		if(mp.count(s[0]))
			++cnt[mp[s[0]]];
	}
	vector<int> perm = {0, 0, 1, 1, 1};
	// for(int i = 0; i < 5; ++i) {
	// 	cout << cnt[i] << " ";
	// }
	// cout << "\n";
	ll ans = 0;
	do {
		// bool cando = true;
		// for(int i = 0; i < 5; ++i) {
		// 	if((cnt[i] > 0) xor (perm[i] > 0)) {
		// 		// cando = false;
		// 	}
		// }
		ll x = 1LL;
		for(int i = 0; i < 5; ++i)
			if(perm[i]) x *= perm[i] * cnt[i];
		ans += x;
	} while(next_permutation(all(perm)));
	cout << ans;
	return 0;
}