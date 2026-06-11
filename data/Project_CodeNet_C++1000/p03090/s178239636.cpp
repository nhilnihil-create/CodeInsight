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
	int n;
	cin >> n;

	vector<pair<int, int>> ans;
	for (int i = n; i >= 2; i--) {
		for (int j = i - 1; j >= 1; j--) {
			if (n % 2 == 1) {
				if (j == n - i) continue;
				ans.eb(i, j);
			}
			else {
				if (j == n + 1 - i) continue;
				ans.eb(i, j);
			}
		}
	}

	cout << ans.size() << endl;
	rep (i, ans.size()) cout << ans[i].fi << " " << ans[i].se << endl;
	return 0;
}