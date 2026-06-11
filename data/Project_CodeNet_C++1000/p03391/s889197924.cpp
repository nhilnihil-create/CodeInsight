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
int a[N], b[N], c[3];
int main(){
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d%d", a + i, b + i);
	rep(i, 0, n) {
		if(a[i] == b[i]) c[0]++;
		if(a[i] < b[i]) c[1]++;
		if(a[i] > b[i]) c[2]++;
	}
	ll ans = 0;
	if(c[0] && c[1] == 0 && c[2] == 0) ans = 0;
	else if(c[1] > 0 && c[2] == 1) {
		rep(i, 0, n)
			if(a[i] <= b[i]) ans += b[i];
	} else{
		ll t = 0;
		rep(i, 0, n) t += b[i];
		rep(i, 0, n) {
			if(a[i] > b[i]) ans = max(ans, t - b[i]);
		} 
	}
	printf("%lld\n", ans);
	return 0;
}
