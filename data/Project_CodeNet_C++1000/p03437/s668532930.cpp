#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x, y;
	cin >> x >> y;
	if (x % y == 0) {
		dunk(-1);
		return 0;
	}
	ll time = 1;
	while (x * time <= 1e18) {
		x *= time;
		if (x % y != 0) {
			dunk(x);
			return 0;
		}
		time++;
	}
	dunk(-1);
	return 0;
}