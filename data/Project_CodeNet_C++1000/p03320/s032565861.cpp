#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
ll N = 1, k;

long double S(ll x) {
	long double suma = 0;
	while (x > 0) {
		suma += x % 10;
		x /= 10;
	}
	return suma;
}

long double Snuke(ll x) {
	return x / S(x);
}

ll f(ll x) {
	ll y = x;
	if (x < 10) return x;
	set<pair<long double, ll> > MS;
	MS.insert(MP(Snuke(x), x));
	ll MOD = 10;
	while (MOD <= x) {
		y = (y / MOD) * MOD + MOD - 1;
		MOD *= 10;
		MS.insert(MP(Snuke(y), y));
	}
	MS.insert(MP(Snuke(MOD - 1), MOD - 1));
	return (*MS.begin()).second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> k;
	while (k--) {
		cout << N << "\n";
		N = f(N + 1);
	}

	return 0;
}
