#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<double, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, k;
	cin >> m >> k;
	int p = pow(2, m);
	if (k >= p) {
		printf("%d\n", -1);
		return 0;
	}
	p--;
	vector<int> vec;
	while (p > -1) {
		if (p == k) {
			p--;
			continue;
		}
		vec.push_back(p);
		p--;
	}
	if (m <= 1) {
		if (m == 0) {
			if (k == 0) printf("%d %d\n", 0, 0);
			else printf("%d\n", -1);
		}
		else {
			if (k == 0) printf("%d %d %d %d\n", 0, 0, 1, 1);
			else printf("%d\n", -1);
		}
		return 0;
	}
	vector<int> rec = vec;
	reverse(all(rec));
	for (int c : vec) cout << c << ' ';
	cout << k << ' ';
	for (int c : rec) cout << c << ' ';
	cout << k << endl;
	return 0;
}
