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
	ll H, W, N, sr, sc;
	cin >> H >> W >> N >> sr >> sc;
	string S, T;
	cin >> S >> T;
	sr--; sc--;

  ll l = 0;
	ll r = W;
	if (S[N-1] == 'L') l++;
	if (S[N-1] == 'R') r--;
	REPR(i, N-1) {
		if (T[i] == 'L') r = min(r+1, W);
		if (T[i] == 'R') l = max(l-1, 0LL);
		if (S[i] == 'L') l++;
		if (S[i] == 'R') r--;
		if (l >= r) {
			PRINT("NO");
			return 0;
		}
	}
	if (!(l <= sc && sc < r)) {
		PRINT("NO");
		return 0;
	}
	l = 0;
	r = H;
	if (S[N-1] == 'U') l++;
	if (S[N-1] == 'D') r--;
	REPR(i, N-1) {
		if (T[i] == 'U') r = min(r+1, H);
		if (T[i] == 'D') l = max(l-1, 0LL);
		if (S[i] == 'U') l++;
		if (S[i] == 'D') r--;
		if (l >= r) {
			PRINT("NO");
			return 0;
		}
	}
	if (!(l <= sr && sr < r)) {
		PRINT("NO");
		return 0;
	}
	PRINT("YES");
	return 0;
}


