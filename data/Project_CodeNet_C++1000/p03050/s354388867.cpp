#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
vi dy = { 0,0,1,-1 };
vi dx = { 1,-1,0,0 };
constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;

int main() {
	ll n;
	cin >> n;
	ll ans = 0;
	ll sqn = sqrt(n);

	rep1(i, sqn) {
		if (n % i)continue;
		if (i >= n / i - 1)continue;
		ans += n / i - 1;
	}

	cout << ans << endl;
}