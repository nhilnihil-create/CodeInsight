#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
const int INF = 1e9;
int main() {
	ll n,m;
	cin >> n >> m;
	int l(0), r(INF);
	rep(i, m) {
		int p, q;
		cin >> p >> q;
		l = max(l, p);
		r = min(r, q);
	}
	int ans = r - l + 1;
	if (ans < 0)cout << 0;
	else cout << ans;
	
	return 0;
}

