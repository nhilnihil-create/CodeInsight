#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
#include<set>
#include<random>
#include<map>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 11451419198109130;
typedef pair<int, int> P;
typedef pair<int,P> PP;
struct edge { int to, cor; };
int x[1005], y[1005];
vector<int>V;
signed main() {
	int n; cin >> n;
	int on = 0, en = 0;
	rep(i, n) {
		cin >> x[i] >> y[i];
		if (abs(x[i] + y[i]) & 1)on++;
		else en++;
	}
	if (on&&en) {
		cout << -1 << endl;
		return 0;
	}
	rep(i, 32) {
		V.push_back(1ll << i);
	}
	if (en) {
		V.push_back(1);
	}

	int sum = 1ll << 32;
	if (on)sum--;
	cout << V.size() << endl;
	rep(i, V.size()) {
		if (i)cout << ' '; cout << V[i];
	}
	cout << endl;
	rep(i, n) {
		int na = x[i] + y[i], nb = x[i] - y[i];
		int ans[35];
		fill(ans, ans + 35, 0);
		int naa = (na + sum) / 2, nbb = (nb + sum) / 2;
		rep(j, 32) {
			if (naa&(1ll << j))ans[j] += 1;
			if (nbb&(1ll << j))ans[j] += 2;
		}
		rep(j, V.size()) {
			if (ans[j] == 0)cout << 'L';
			else if (ans[j] == 1)cout << 'U';
			else if (ans[j] == 2)cout << 'D';
			else cout << 'R';
		}
		cout << endl;
	}
}