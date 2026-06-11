#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n;
	ll ans = 0;
	string str,march = "MARCH";
	set<char>s;
	for (auto ma : march)s.insert(ma);
	cin >> n;
	vector<string>name;
	rep(i, n) {
		cin >> str;
		if (!s.count(str[0]))continue;
		name.push_back(str);
	}
	map<char, ll>m;
	for (auto mp : name)m[mp[0]]++;
	rep(i, 3) for (int j = i + 1; j < 4; j++)for (int k = j + 1; k < 5; k++) {
		ans += m[march[i]] * m[march[j]] * m[march[k]];
	}

	cout << ans << endl;
	return 0;
}

