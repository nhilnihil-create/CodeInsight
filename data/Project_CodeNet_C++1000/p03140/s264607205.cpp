#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;

using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	long long g = gcd(a, b);
	return a / g * b;
}

int main() {
	int n; cin >> n;

	string a, b, c; cin >> a >> b >> c;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] && b[i] == c[i])cnt += 0;
		else if (a[i] == b[i] || b[i] == c[i] || a[i] == c[i])cnt++;
		else if (a[i] != b[i] && b[i] != c[i] && a[i] != c[i])cnt += 2;
	}
	cout << cnt;
}
