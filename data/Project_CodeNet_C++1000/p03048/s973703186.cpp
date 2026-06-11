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
using P = pair<int, int>;


int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;

	ll ans = 0;
	for (int i = 0; i <= 3000; i++) {
		for (int j = 0; j <= 3000; j++) {
			if (n - i * b - j * g >= 0) {
				if ((n - i * b - j * g) % r == 0) ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}