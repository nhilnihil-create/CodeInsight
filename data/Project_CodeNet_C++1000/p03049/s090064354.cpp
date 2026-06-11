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
	int n;
	cin >> n;
	vector<string> v(n);
	rep(i,n) cin >> v[i];
	ll cab = 0;
	ll ca = 0;
	ll cb = 0;
	ll c = 0;
	rep(i,n) {
		string s = v[i];
		if (s[0] == 'B' && s[s.size() - 1] == 'A') c++;
		else if (s[0] == 'B') cb++;
		else if (s[s.size() - 1] == 'A') ca++;
		for (int j = 0; j < s.size() - 1; j++) {
			string t = s.substr(j, 2);
			if (t == "AB") cab++;
		}
	}
	if (cb == 0 && ca == 0) {
		cout << cab + max((ll)0, c - 1) << endl;
	} else {
		cout << cab + min(ca + c, cb + c) << endl;
	}
}

int main() {
	solve();
	return 0;
}