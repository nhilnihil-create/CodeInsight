#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
inline int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
inline int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
inline int mul(int a, int b) {return 1ll * a * b % P;}
inline int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----
const int N = 202020;
int n;
int ar[N];
int main(){
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", ar + i);
	ll a = ar[0], b = 0, c = ar[1] + ar[2], d = 0;
	rep(i, 3, n) d += ar[i];
	ll ans = 1e18;
	for(int l = 0, mid = 1, r = 2; mid < n - 2; mid++) {
		b += ar[mid];
		c -= ar[mid];
		if(mid < r && l < mid)
			ans = min(ans, max(max(a, b), max(c, d)) - min(min(a, b), min(c, d)));
		while(l + 1 < mid && abs(a - b) >= abs(a + ar[l + 1] - (b - ar[l + 1]))) {
			l++;
			a += ar[l];
			b -= ar[l];
			if(mid < r && l < mid)
				ans = min(ans, max(max(a, b), max(c, d)) - min(min(a, b), min(c, d)));
		}
		while(r + 1 < n - 1 && abs(c - d) >= abs(c + ar[r + 1] - (d - ar[r + 1]))) {
			r++;
			c += ar[r];
			d -= ar[r];
			if(mid < r && l < mid)
				ans = min(ans, max(max(a, b), max(c, d)) - min(min(a, b), min(c, d)));
		}
		ans = min(ans, max(max(a, b), max(c, d)) - min(min(a, b), min(c, d)));
	}
	printf("%lld\n", ans);
	return 0;
}

