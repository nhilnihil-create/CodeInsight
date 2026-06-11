#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
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

ll gcd(ll i, ll j) { return i % j ? gcd(j, i % j) : j; }

int main() {
	
	int n, x;
	cin >> n >> x;
	int ans = 0;
	rep(i, n) {
		int y;
		cin >> y;
		ans = gcd(ans, abs(x - y));
	}
	cout << ans << endl;

}