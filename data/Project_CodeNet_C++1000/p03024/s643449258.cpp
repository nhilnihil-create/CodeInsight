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
	string s;
	cin >> s;
	map<char, int>mp;
	for (auto c : s)mp[c]++;
	if (mp['x'] < 8){
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}

