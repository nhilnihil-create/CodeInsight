#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <tuple>
#include <functional>
#include <bitset>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmax(T &a, const T&b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T&b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

ll mod = 1000000007;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> p(300000);
	vector<ll> dp(n);
	dp[0] = 1;
	p[a[0]] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1];
		if (a[i] != a[i - 1]) {
			dp[i] += p[a[i]];
			dp[i] %= mod;
			p[a[i]] = dp[i];
		}
	}
	cout << dp[n - 1] << endl;
}
