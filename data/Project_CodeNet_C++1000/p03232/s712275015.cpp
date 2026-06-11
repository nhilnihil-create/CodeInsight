#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> P;

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val)
{
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e18;
const ll mod = 1e9 + 7;

ll modpow(ll a, ll b, ll c) {
	if (b == 0)return 1;
	else if (b % 2 == 0) {
		ll d = modpow(a, b / 2, c);
		return (d * d) % c;
	}
	else return (a * modpow(a, b - 1, c)) % c;
}

ll factm(ll n, ll mod) {
	if(n == 0)return 1;
	return ((n * factm(n - 1,mod)) % mod);
}

int main(){
	IOS;
	ll n;
	cin >> n;
	vl a(n + 1),s(n + 1);
	s[0] = 0;
	for(int i = 1;i <= n;i++){	
		s[i] = s[i - 1] + modpow(i, mod - 2, mod); //1/1 + 1/2 + 1/3...
	}
	for(ll i = 1;i <= n;i++)cin >> a[i];
	ll ans = 0;
	for(ll i = i;i <= n;i++) {
		ans += ((s[i] + s[n - i + 1] - 1) % mod * a[i]) % mod; //P(1) + P(2) + ...
		ans %= mod;
	}
	ans *= factm(n,mod);
	ans %= mod;
	dump(ans);
}