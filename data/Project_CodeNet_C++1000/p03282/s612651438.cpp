#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	ll k; string s;
	cin >> s >> k;
	int non_one;
	if (s[0] != '1') {
		cout << s[0] << endl;
		return 0;
	}

	rep(i,s.size()) {
		if (s[i] != '1') {non_one = i; break;}
	}
	//non_one++;
	if (non_one+1 > k) cout << 1 << endl;
	else cout << s[non_one] << endl;
	return 0;
}