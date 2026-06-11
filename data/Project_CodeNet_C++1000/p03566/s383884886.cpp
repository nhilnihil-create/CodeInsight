/*#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <array>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SORT(c) sort((c).begin(),(c).end())

typedef long long ll;
const ll INF = LLONG_MAX - 100;
const ll mod = 1e9 + 7;
const int MAX_N = 5e5 + 5;
int dx[] = { -1LL,0,1LL,0 }, dy[] = { 0,1LL,0,-1LL };
vector<ll> prime;

ll inv[MAX_N], fac[MAX_N];

inline ll GCD(ll a, ll b) { ll c; while (b != 0) { c = a % b; a = b; b = c; }return a; }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline ll POW(ll a, ll b) { ll c = 1LL; while (b > 0) { if (b & 1LL) { c = a * c%mod; }a = a * a%mod; b >>= 1LL; }return c; }
inline void _nCr() { fac[0] = 1LL; for (int i = 1LL; i < MAX_N; i++) { fac[i] = fac[i - 1LL] * i%mod; }for (int i = 0; i < MAX_N; i++) { inv[i] = POW(fac[i], mod - 2); } }
inline ll nCr(ll n, ll r) { return (fac[n] * inv[r] % mod)*inv[n - r] % mod; }
inline void PRI(ll n) { bool a[n + 1LL]; for (int i = 0; i < n + 1LL; i++) { a[i] = 1LL; }for (int i = 2; i < n + 1LL; i++) { if (a[i]) { prime.pb(i); ll b = i; while (b <= n) { a[b] = 0; b += i; } } } }

int cnt[26];

signed main() {
	int n; cin >> n;
	int t[n+2], v[n+2];
	t[0] = v[0] = t[n+1] = v[n+1] = 0;
	FOR (i,1,n+1) cin >> t[i];
	FOR (i,1,n+1) cin >> v[i];
	FOR (i,1,n+1) {
		v[i] = min(v[i],v[i-1]+t[i]);
	}
	FOR (i,0,n) {
		v[n-i] = min(v[n-i],v[n-i+1]+t[n-i]);
	}
	float ans = 0;
	FOR (i,1,n+1) {
		float tmp = 0;
		float l = min(v[i],v[i-1]);
		float r = min(v[i],v[i+1]);
		float time = (t[i] + abs(r-l));
		float high = min(l,r) + time / 2;
		tmp += min(l,r) * t[i];
		tmp += time * time / 4;
		tmp -= (float)abs(r-l) * (float)abs(r-l) / 2;
		if (high > v[i]) {
			tmp -= (high - (float)v[i]) * (high - (float)v[i]);
		}
		ans += tmp;
	}
	cout << fixed << setprecision(8) << ans << endl;
}
