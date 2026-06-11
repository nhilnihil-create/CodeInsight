#include <bits/stdc++.h> 
using namespace std;

#define sz(x) (int)x.size() 
#define pb push_back 
#define mp make_pair 
#define fi(a, b) for(int i=a; i<=b; i++) 
#define fj(a, b) for(int j=a; j<=b; j++) 
#define fo(a, b) for(int o=a; o<=b; o++) 
#define fdi(a, b) for(int i=a; i>=b; i--) 
#define fdj(a, b) for(int j=a; j>=b; j--) 
#define fdo(a, b) for(int o=a; o>=b; o--) 

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#else
#define err(...) while(false) {}
#endif

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef vector<int> vi; 
typedef vector<pii> vpii; 
typedef vector<pll> vpll; 
typedef long double ld;

/////////////////////////////////

ll const INF = 2e18;
int a, b;
ll c;

ll geta(ll k) {
	if (k >= a) k++;
	return k;
}

ll getb(ll k) {
	if (k >= b) k++;
	return k;
}

ll mult(ll a, ll b) {
	if (a == 0 || b == 0) return 0LL;
	if (INF / a < b) return INF;
	return a * b;
}

bool can(ll k) {	
//	k = 2;
	ll l1 = k / 2 - 10;
	ll r1 = k / 2 + 10;
	l1 = max(1LL, l1);	
	r1 = min(k, r1);
	ll y = 0;
	for (ll i = l1; i <= r1; i++) {
		ll v = mult(geta(i), getb(k - i + 1));
//		err("k = %lld l1 = %lld r1 = %lld y = %lld i = %lld v = %lld\n", k, l1, r1, y, i, v);
		y = max(y, v);			
	}
	return (y < c);
}

void solve() {
	c = (ll) a * b;
	ll l = 0;
	ll r = INF;
	while (r - l > 1) {
		ll h = (l + r) / 2;
		if (can(h)) {
//			err("can : h = %lld\n",h);
			l = h;
		} else {
			r = h;
		}
	}
	printf("%lld\n", l);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {  
		scanf("%d %d", &a, &b);
		solve();		
	}

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}