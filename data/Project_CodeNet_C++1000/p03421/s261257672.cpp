#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 10000;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef pair<int, PP> PPP;
struct edge { int to; int cost; };

signed main() {
	int n, a, b; cin >> n >> a >> b;
	vector<int>V;
	int flg = 0;
	if (a + b > n + 1)flg++;
	int mb = (n+a-1) / a;
	if (mb > b)flg++;
	for(int i=n-1;i>=0;i--) {
		int cnt = i + 1 + (n - 1 - i) / a;
		if (cnt == b) {//cout << i << endl;
			V.push_back(a);
			rep(j, i)V.push_back(1);
			rep(j, (n - i - 1) / a) {
				if ((!j)&&(n-i)%a)V.push_back((n - i) % a);
				else V.push_back(a);
			}
			break;
		}
	}
	if (flg) {
		cout << -1 << endl; return 0;
	}

	int mn = 1;
	stack<int>S;
	for (int i = V.size() - 1; i >= 0; i--) {
		rep(j, V[i]) {
			S.push(mn + V[i] - 1 - j);
		}
		mn += V[i];
	}
	while (S.size()) {
		cout << S.top();
		S.pop();
		if (S.size())cout << ' ';
	}cout << endl;
}