#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}
const int N = 212345;
const int mod = 1000*1000*1000+7;
ll fpow (ll b, ll e) {
	if (!e) return 1;
	ll r = fpow(b, e/2);
	r = (r*r) % mod;
	return e % 2 ? (r * b) % mod : r;
}
ll fat[N], inv[N], calc[N];
int v[N];
int main (void) {
	fat[0] = inv[0] = 1;
	for (int i = 1; i < N; i++) {
		fat[i] = fat[i-1] * i % mod;
		inv[i] = fpow(fat[i], mod-2);
	}
	int n;
	rd(n); 
	for (int i = 0; i < n; i++) rd(v[i]);
	for (int i = 2; i <= n; i++) 
		calc[i] = fat[n] * inv[i] % mod * fat[i-1] % mod;
	
	ll left = 0;
	ll right = 0;
	int sz = 1;
	for (int i = 1; i < n; i++) 
		right = (right + calc[++sz]) % mod;
	ll ans = 0;
	int sz2 = 1;
	ans = (ans + v[0] * (fat[n] + right)) % mod;
	for (int i = 1; i < n; i++) {
		right = (right - calc[sz--] + mod) % mod;
		left = (left + calc[++sz2]) % mod;
		ans = (ans + v[i] * (fat[n] + right + left)) % mod;
	}
	cout << ans << endl;
	return 0;
}