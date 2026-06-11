#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	ll a, b;
	cin >> a >> b;

	if (a % 2 == 1 && b % 2 == 1) {
		ll t = (b - a) / 2;
		if (t % 2 == 0) t = 0;
		else t = 1;
		ll ans = a ^ t;
		cout << ans << endl;
	} else if (a % 2 == 0 && b % 2 == 0) {
		ll t = (b - a) / 2;
		if (t % 2 == 0) t = 0;
		else t = 1;
		ll ans = t ^ b;
		cout << ans << endl;
	} else if (a % 2 == 0 && b % 2 == 1) {
		ll t = (b + 1 - a) / 2;
		if (t % 2 == 0) cout << 0 << endl;
		else cout << 1 << endl;
	} else {
		ll t = (b - (a + 1)) / 2;
		if (t % 2 == 0) t = 0;
		else t = 1;
		ll ans = t ^ a ^ b;
		cout << ans << endl;
	}
}