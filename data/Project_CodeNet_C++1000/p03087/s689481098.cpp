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
	vector<int> sum(n + 1);
	rep(i, n) {
		if (s.substr(i, 2) == "AC") sum[i + 1]++;
		sum[i + 1] += sum[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		cout << sum[r] - sum[l] << endl;
	}
	return 0;
}
