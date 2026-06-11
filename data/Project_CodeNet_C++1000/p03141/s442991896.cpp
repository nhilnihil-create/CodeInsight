#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	V<T> dish(n);
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		dish[i] = make_tuple(a + b, a, b);
	}

	sort(all(dish), greater<T>());

	ll taka = 0, aoki = 0;
	rep(i, n) {
		if (i & 1) aoki += get<2>(dish[i]);
		else taka += get<1>(dish[i]);
		
	}

	cout << taka - aoki << endl;

}