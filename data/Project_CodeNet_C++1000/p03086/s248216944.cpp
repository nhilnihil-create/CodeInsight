#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

int main() {
	string s;
	cin >> s;
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A' || s[i] == 'G' || s[i] == 'C' || s[i] == 'T') {
			cnt++;
		}
		else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	ans = max(ans, cnt);
	cout << ans << endl;
	return 0;
}