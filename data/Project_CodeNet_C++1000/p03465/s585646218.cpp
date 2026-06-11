#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

ll MOD = (ll) 1e9 + 9;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) (LONG_LONG_MAX - 3ll) / 2ll;
const ld EPS = (ld) 1e-8;
const ll P = 104107;

ll mul(ll a, ll b){
	return (a * b) % MOD;
}

ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return mul(b, pw(b, p - 1));
	return pw(mul(b, b), p / 2);
}
ll inv(ll x){
	return pw(x, MOD - 2);
}

bitset<2000010> knap;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll v, s = 0;
	knap[0] = 1;
	for(int i = 0; i < n; i++){
		cin >> v;
		s += v;
		knap |= (knap << v);
	}
	ll mx = 0;
	for(int i = 1; i <= s/2; i++) if(knap[i]) mx = i;
	cout << s - mx;
	return 0;
}


