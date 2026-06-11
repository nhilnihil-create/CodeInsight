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
	int a, b, c;
	cin >> a >> b >> c;
	map<int, int>mp;
	mp[a]++; mp[b]++; mp[c]++;
	for (auto m : mp) {
		if (m.second == 1)cout << m.first << endl;
	}
	return 0;
}

