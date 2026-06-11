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

	ll n, a, b, c, d, e;
	cin >> n >> a >> b >> c >> d >> e;
	
	ll mn = a;
	mn = min(mn, b);
	mn = min(mn, c);
	mn = min(mn, d);
	mn = min(mn, e);

	ll ans = (n + mn - 1) / mn + 4;

	cout << ans << endl;
}