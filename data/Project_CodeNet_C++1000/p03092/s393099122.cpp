#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

//i未満左端、j未満はignore
ll dp[5001][5001];

struct BIT {
private:
	vector<int> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, int w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	int sum(int a) {
		int ret = 0;
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	int sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

void solve() {
	int n; ll a, b; cin >> n >> a >> b;
	vector<int> p(n),invp(n);
	rep(i, n) {
		cin >> p[i]; p[i]--; invp[p[i]] = i;
	}
	BIT bi(n);
	rep(i, 5001) {
		rep(j, 5001) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	rep(i, n) {
		int id = invp[i];
		rep(j, n+1) {
			//right
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]+b);
			//left
			if (j <= id) {
				int num = bi.sum(j, id);
				num = id - j - num;
				//cout << i << " " << j << " " << num << endl;
				dp[i + 1][id+1] = min(dp[i + 1][id+1], dp[i][j] + a * num);
			}
			else {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			}
		}
		bi.add(id, 1);
	}
	ll ans = INF;
	rep(i, n + 1) {
		ans = min(ans, dp[n][i]);
	}
	cout << ans << endl;
}
int main() {
	solve();
	//stop
	return 0;
}
