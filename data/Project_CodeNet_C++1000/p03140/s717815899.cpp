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
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
	int n;
	cin >> n;
	string a, b, c;
	cin >> a >> b >> c;

	map<char, int> mp[n];
	int ans = 0;
	rep (i, n) {
		mp[i][a[i]]++;
		mp[i][b[i]]++;
		mp[i][c[i]]++;
		if (mp[i][a[i]] == 3) {
			continue;
		}
		if (mp[i][a[i]] == 1 && mp[i][b[i]] == 1 && mp[i][c[i]] == 1) {
			ans += 2;
			continue;
		}
		ans += 1;
	}

	cout << ans << endl;
	return 0;
}