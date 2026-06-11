#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	int n, k;
	string s;
	cin >> n >> k >> s;
	int str = 1;
	vi per;

	if (s[0] == '0')per.push_back(0);
	rep(i, n - 1) {
		if (s[i] == s[i + 1])str++;
		else {
			per.push_back(str);
			str = 1;
		}
	}
	per.push_back(str);
	if (s[n - 1] == '0')per.push_back(0);

	int m = per.size();
	if (m == 1) {
		cout << per[0] << endl;
		return 0;
	}
	vi sum(m + 1);
	rep(i, m)sum[i + 1] = sum[i] + per[i];
	
	int ans = 1;
	rep(i, m / 2) {
		ans = max(ans, sum[min(2 * i + 2 * (k - 1) + 3, m)] - sum[2 * i]);
	}
	cout << ans << endl;

}