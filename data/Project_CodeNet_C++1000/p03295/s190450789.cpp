#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", x);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;



int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> Q(m);
	rep (i, m) cin >> Q[i].se >> Q[i].fi;

	sort(rng(Q));

	int ans = 1;
	int pos = -1;
	rep (i, m) {
		if (pos == -1) {
			pos = Q[i].fi;
			continue;
		}
		if (Q[i].se >= pos) {
			pos = Q[i].fi;
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}