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
	vector<int> c(n - 1), s(n - 1), f(n - 1);
	rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
	for (int i = 0; i < n; ++i) {
		int now = 0;
		for (int j = i; j < n - 1; ++j) {
			if (now < s[j]) now = s[j];
			else if (now % f[j] == 0);
			else now = now + f[j] - now % f[j];
			now += c[j];
		}
		cout << now << endl;
	}
	return 0;
}
