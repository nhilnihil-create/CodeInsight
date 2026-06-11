#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<ll> sum;
	sum.push_back(0);
	rep(i, n) {
		int c = 0;
		char prev = s[i];
		while (s[i] == prev) {
			c++;
			i++;
		}
		i--;
		sum.push_back(c);
	}
	int sz = sum.size();
	rep(i, sz - 1) sum[i + 1] += sum[i];
	ll ans = 0;
	if (s[0] == '1') {
		rep(i, sz) {
			if (i % 2) chmax(ans, sum[min(sz - 1, i + k * 2)] - sum[i]);
			else chmax(ans, sum[min(sz - 1, i + k * 2 + 1)] - sum[i]);
		}
	}
	else {
		rep(i, sz) {
			if (i % 2) chmax(ans, sum[min(sz - 1, i + k * 2 + 1)] - sum[i]);
			else chmax(ans, sum[min(sz - 1, i + k * 2)] - sum[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
