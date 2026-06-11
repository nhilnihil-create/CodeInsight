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
typedef tuple<ll, ll, ll> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	V<ll> a(n), b(n),c(n);
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	rep(i, n)c[i] = b[i] - a[i];

	ll k = 0;
	rep(i, n) {
		if (c[i] > 0)k += c[i] / 2;
		else k += c[i];
	}

	if (k >= 0)cout << "Yes" << endl;
	else cout << "No" << endl;

}