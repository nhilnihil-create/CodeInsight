#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<ll, ll>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
const int INF = 1e9;
int main() {
	int n, m;
	cin >> n >> m;
	//vector<int>a(n);
	vector<P>b(m);

	rep(i, n) {
		ll a;
		cin >> a;
		b.push_back(make_pair(a, 1));
	}
	
	rep(i, m) {
		ll B, C;
		cin >> B >> C;
		b.push_back(make_pair(C, B));
	}
	sort(b.rbegin(), b.rend());
	int k = 0;
	ll ans(0);
	for (auto p : b) {
		if (k + p.second <= n) {
			ans += p.first * p.second;
			k += p.second;
		}
		else {
			ans += p.first * (n - k);
			break;
		}
	}
	cout << ans;
	return 0;
}

