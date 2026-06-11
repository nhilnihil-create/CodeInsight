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
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> sum1(n + 1), sum2(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		if (s.substr(i, 2) == "AC") {
			sum1[i + 1]++;
		}
		sum1[i + 1] += sum1[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		int ans = sum1[r] - sum1[l];
		printf("%d\n", ans);
	}
	return 0;
}
