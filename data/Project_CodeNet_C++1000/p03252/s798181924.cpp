#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	if (n != t.size()) {
		cout << "No" << endl;
		return;
	}
	vector<int> v(26), chk(26);
	rep(i, 26) v[i] = i;
	rep(i,n) {
		char c = s[i];
		char d = t[i];
		if (chk[c - 'a']) {
			if (v[c - 'a'] == d - 'a') continue;
			cout << "No" << endl;
			return;
		} else {
			int l = 0;
			rep(j, 26) {
				if (v[j] == d - 'a') l = j;
			}
			if (!chk[l]) {
				swap(v[c - 'a'], v[l]);
				chk[c - 'a']++;
			} else {
				cout << "No" << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
}

int main() {
	solve();
	return 0;
}