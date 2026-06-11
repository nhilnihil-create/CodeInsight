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

int mp[3][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	rep(i, 3)rep(j, 3) cin >> mp[i][j];
	rep(a, 101)rep(b, 101) {
		if (a + b != mp[0][0]) continue;
		vector<int> a_(3), b_(3);
		rep(i, 3) a_[i] = mp[0][i] - b;
		rep(i, 3) b_[i] = mp[i][0] - a;
		bool ok = true;
		rep(i, 3)rep(j, 3) {
			if (mp[i][j] != a_[j] + b_[i]) ok = false;
		}
		if (ok) {
			printf("%s\n", "Yes");
			return 0;
		}
	}
	printf("%s\n", "No");
	return 0;
}
