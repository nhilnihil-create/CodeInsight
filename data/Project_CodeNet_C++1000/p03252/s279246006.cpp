#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, start_index, num)  (a).begin()+(start_index),(a).begin()+(num)

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int n = SZ(s1);
	map<char, char> mp;
	FOR(i, 'a', 'z') {
		mp[i] = '?';
	}
	
	FOR(i, 0, n - 1) {
		for (auto obj : mp) {
			if (obj.second == s2[i]) {
				if (obj.first != s1[i]) {
					ps(No);
					return 0;
				}
			}
		}
		if (mp[s1[i]] == '?') {
			mp[s1[i]] = s2[i];
		}
		else {
			if (mp[s1[i]] != s2[i]) {
				ps(No);
				return 0;
			}
		}
	}
	ps(Yes);
	return 0;
}