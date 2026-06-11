#include <bits/stdc++.h>


#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<int, int> P;
typedef tuple<int, int, int> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

const ll mod = 1000000007;

ll gcd(ll a, ll b) { while (b) a %= b, swap(a, b); return abs(a); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
	ll n;
	cin >> n;
	//n/m >= m ならば
	//n/m = n % m とはならない
	//n >= m*m はチェック不要
	//while(i*i <= n) 不要
	//i > sqrt(n)
	//36
	//36-3 / 11 = 3
	//36-4 / 8 = 4
	//t = n - i;
	//n/i == t/i;
	//n / i = n % i

	double u = sqrt(n)+1;
	ll ut = (ll)u;
	ll sum = 0;
	for (ll i = ut; i > 0; i--) {
		auto opm = n - i;
		if (opm % i == 0) {
			auto m = opm / i;
			if (m > 0) {
				if (n / m == n % m) {
					sum += m;
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}
