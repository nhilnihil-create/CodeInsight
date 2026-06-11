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
	ll N;
	cin >> N;

	vector<ll> A(N);
	REP(i, N) cin >> A[i];

	if (A[0] != 0) {
		PRINT(-1);
		return 0;
	}
	A.push_back(0);
	ll pre = A[0];
	ll ans = 0;
	FOR(i, 1, N+1) {
		if (pre >= A[i]) {
			ans += pre;
		} else if (pre+1 == A[i]) {
			//ans += A[i] - pre;
		} else {
			PRINT(-1);
			return 0;
		}
		pre = A[i];
	}
	PRINT(ans);
	return 0;
}
