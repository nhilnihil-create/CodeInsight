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
	int n, m,k,s,cnt=0,lampcnt=0,ans=0;
	cin >> n >> m;
	vector<vector<int>>lamp(m, vector<int>(n,0));
	vector<int>lampm(m);
	vector<int>si(n, 0), sii(n, 0);
	rep(i, m) {
		cin >> k;
		rep(j, k) {
			cin >> s;
			lamp[i][--s] = 1;
		}
	}
	rep(i,m)cin >> lampm[i];

	for (int bit = 0; bit < (1 << n); bit++) {
		si = sii;
		rep(i,n){
			if (bit & (1 << (n - 1)) >> i) {
				si[i] = 1;
			}
		}
		lampcnt = 0;
		rep(i, m) {
			cnt = 0;
			rep(j, n) {
				if (si[j] ==1 &&lamp[i][j] == 1)cnt++;
			}
			if (cnt % 2 == lampm[i])lampcnt++;
		}
		if (lampcnt == m)ans++;
	}
	cout << ans << endl;
	return 0;
}

