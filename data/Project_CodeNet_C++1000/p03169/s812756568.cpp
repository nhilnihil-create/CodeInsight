#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

#include <bits/stdc++.h>
using namespace std;

template<typename T>
void cmpmax(T* reference, T value) {
	*reference = max(*reference, value);
}

template<typename T>
void cmpmin(T* reference, T value) {
	*reference = min(*reference, value);
}

const ll mod = 998244353;

static const ll INF = 1e15;


int main() {
	int n;
	cin >> n;
	vector<int> cs(4,0);
	rep(i, n) {
		int a;
		cin >> a;
		cs[a]++;
	}
	vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, 0)));
	for (int k = 0; k <= n; k++) {
		for (int j = 0; j <= n; j++) {
			for (int i = 0; i <= n; i++) {
				if (i == 0 && j == 0 && k == 0) continue;
				if (i + j + k > n) continue;
				double left = i + j + k;
				double right = 0;
				if (i) {
					right += i * dp[i - 1][j][k];
				}
				if (j && i+1<=n) {
					right += j * dp[i + 1][j - 1][k];
				}
				if (k && j + 1 <= n) {
					right += k * dp[i][j + 1][k-1];
				}
				right += n;
				dp[i][j][k] = right / (i + j + k);
			}
		}
	}
	cout << fixed << setprecision(10);
	cout << dp[cs[1]][cs[2]][cs[3]] << endl;
	return 0;
}
	