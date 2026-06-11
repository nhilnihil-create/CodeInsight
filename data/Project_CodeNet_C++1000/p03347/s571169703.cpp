#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
vi dy = { 0,0,1,-1 };
vi dx = { 1,-1,0,0 };
constexpr auto INF = 1050000000;
constexpr auto MOD = 1000000007;


int main() {

	int n;
	cin >> n;
	vi a(n);
	rep(i, n)cin >> a[i];

	bool can = true;

	vi mna(n,0), mxa(n,0);
	int mn = 1;


	rep(i, n - 1) mxa[i + 1] = a[i] + 1;

	ll ans = 0;

	rep(i, n) {
		mn--;
		if (a[n - 1 - i] < mn || mxa[n - i - 1] < a[n - 1 - i]) {
			can = false;break;
		}

		if (a[n - 1 - i] == mn)continue;

		ans += a[n - 1 - i];
		mn = a[n - 1 - i];
	}

	if (can)cout << ans << endl;
	else cout << -1 << endl;

}