#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
#define rSORT(a, i) sort(all(a),(i))

using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;
const int MAX_N = 110000; 
constexpr double EPS = 1E-11;

using namespace std;

//fixed << setprecision(10)

int main() {
	int n, a, b; cin >> n >> a >> b;

	int mx = min(a, b);
	int mn = 0;

	if (a + b > n) {
		mn = a + b - n;
	}
	else if (a == b && a == n) {
		mn = 0;
	}

	cout << mx << ' ' << mn << endl;
}