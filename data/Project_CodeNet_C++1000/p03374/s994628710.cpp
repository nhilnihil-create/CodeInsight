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
const int N = 101010;
int n, v[N];
ll c, x[N];
int main(){
	scanf("%d%lld", &n, &c);
	rep(i, 0, n) scanf("%lld%d", x + i, v + i);
	ll ans = 0, s = 0;
	rep(i, 0, n) {
		s += v[i];
		ans = max(ans, s - x[i]);
	}
	s = 0;
	for(int i = n - 1; ~i; i--) {
		s += v[i];
		ans = max(ans, s - (c - x[i]));
	}
	multiset<ll> sum;
	sum.insert(0);
	s = 0;
	for(int i = n - 1; ~i; i--) {
		s += v[i];
		ll t = s - (c - x[i]);
		sum.insert(-t);
	}
	ll ns = 0;
	rep(i, 0, n) {
		ll t = s - (c - x[i]);
		s -= v[i];
		ns += v[i];
		sum.erase(sum.find(-t));
		ans = max(ans, ns - 2 * x[i] - *sum.begin());
	}
	sum.clear();
	sum.insert(0);
	s = 0;
	rep(i, 0, n) {
		s += v[i];
		ll t = s - x[i];
		sum.insert(-t);
	}
	ns = 0;
	for(int i = n - 1; ~i; i--) {
		ns += v[i];
		ll t = s - x[i];
		s -= v[i];
		sum.erase(sum.find(-t));
		ans = max(ans, ns - 2 * (c - x[i]) - *sum.begin());
	}
	printf("%lld\n", ans);
	return 0;
}
