#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	string s;
	ll sum=0, wcnt = 0;
	cin >> s;
	map<char, int>mp;
	rep(i, s.size()) {
		if (s[i] == 'W') {
			sum += (ll)i - wcnt;
			wcnt++;
		}
	}
	cout << sum << endl;
}
