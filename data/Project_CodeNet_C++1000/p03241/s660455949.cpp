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
constexpr auto INF = INT_MAX / 2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, m;
	cin >> n >> m;

	vi dv(0);

	rep1(i, sqrt(m)) {
		if (m % i)continue;
		dv.push_back(i);
		dv.push_back(m / i);
	}

	int ans = 1;

	rep(i, dv.size())if (m / dv[i] >= n)ans = max(ans, dv[i]);

	cout << ans << endl;

}