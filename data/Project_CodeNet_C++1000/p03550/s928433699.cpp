#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX / 2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, z, w;
	cin >> n >> z >> w;

	vi a(n);
	rep(i, n)cin >> a[i];

	if (n == 1)cout << abs(a[0] - w) << endl;
	else cout << max(abs(a[n - 1] - w), abs(a[n - 1] - a[n - 2]));

}