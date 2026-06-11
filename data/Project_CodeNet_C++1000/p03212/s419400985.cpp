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
	int ans = 0;
	function<void(long long)> Dfs = [&](long long v) {
		if (v != 0) {
			string tmp = to_string(v);
			if (tmp.find("3") != string::npos && tmp.find("5") != string::npos && tmp.find("7") != string::npos) ans++;
		}
		if (v * 10 + 3 <= n) Dfs(v * 10 + 3);
		if (v * 10 + 5 <= n) Dfs(v * 10 + 5);
		if (v * 10 + 7 <= n) Dfs(v * 10 + 7);
	};
	Dfs(0);
	cout << ans << endl;
	return 0;
}