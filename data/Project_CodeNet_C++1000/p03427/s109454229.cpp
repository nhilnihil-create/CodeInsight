#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;

int get(ll x) {
	int res = 0;
	do {
		res += x % 10;
		x /= 10;
	}	while (x);
	return res;
}

int len(ll x) {
	int res = 0;
	do {
		res++;
		x /= 10;
	}	while (x);
	return res;
}

ll pw(int x, int y) {
	ll res = 1;
	while (y--) {
		res *= x;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	ll n;
	cin >> n;
	int ans = get(n);
	ll nine = 0;
	while (true) {
		n /= 10;
		if (n == 0) {
			break;
		}
		n--;
		nine = nine * 10 + 9;
		ll tmp = pw(10, len(nine));
		n = n * tmp + nine;
		ans = max(ans, get(n));
		n = (n - nine) / tmp;
		n++;
	}
	cout << ans;
}
