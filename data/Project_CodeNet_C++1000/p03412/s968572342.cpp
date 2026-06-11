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
int a[N], b[N], c[N], d[N];

int main(){
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	rep(i, 0, n) scanf("%d", b + i);
	ll ans = 0;
	rep(bit, 0, 31) {
		ll up[4] = {1ll << bit};
		rep(i, 1, 4) up[i] = up[i - 1] + up[0];
		ll t = up[1] - 1; 
		rep(i, 0, n) c[i] = a[i] & t;
		rep(i, 0, n) d[i] = b[i] & t;
		sort(c, c + n);
		sort(d, d + n);
		ll cnt = 0;
		for(int j = 0; j < 3; j += 2) {
			rep(i, 0, n) {
				int l = 0, r = 0;
				l = lower_bound(d, d + n, up[j] - c[i]) - d;
				r = lower_bound(d, d + n, up[j + 1] - c[i]) - d;
				cnt += r - l;
			}
		}
	//	de(cnt);
		ans |= (1 << bit) * (cnt % 2);
	}
	printf("%lld\n", ans);
	return 0;
}
