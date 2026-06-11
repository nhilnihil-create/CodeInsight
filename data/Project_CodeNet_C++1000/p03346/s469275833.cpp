#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) {
		int x;
		cin >> x;
		x--;
		p[x] = i;
	}
	int t = 1, ans = 1;
	rrep(i, n) {
		if (p[i] > p[i - 1]) {
			t++;
		}
		else {
			t = 1;
		}
		maxs(ans, t);
	}
	cout << n - ans << endl;
	return 0;
}
