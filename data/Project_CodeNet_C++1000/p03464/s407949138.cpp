#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n-1; i >= 0LL; i--)
#define FOR(i, n, m) for(ll i = n; i < (ll)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define INFD 1e18
#define PI 3.14159265358979
#define MOD 1000000007
#define vl vector<ll>

vector<ll> dx = {-1, 1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
	ll K;
	cin >> K;

	vector<ll> A(K+1);
	A[0] = 1;
	REP(i, K) cin >> A[i+1];
	if (A.back() != 2) {
		PRINT(-1);
		return 0;
	}
	ll mi = 2;
	ll ma = 2;
	for(ll i = K; i > 0; i--) {
		ll tmin = mi;
		ll tmax = ma;

		mi = ((tmin-1)/A[i-1]+1)*A[i-1];
		ma = ((tmax+A[i]-1)/A[i-1])*A[i-1];
		if (ma < mi) {
			PRINT(-1);
			return 0;
		}
	}
	PRINT(mi << " " << ma);
	return 0;
}


