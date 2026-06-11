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
int T;
int a, b;
int main(){
	scanf("%d", &T);
	rep(cas, 0, T) {
		scanf("%d%d", &a, &b);
		ll ab = 1ll * a * b, sq = sqrt(ab);
		if(a > b) swap(a, b);
		ll ans = (a - 1) * 2, len = max(0ll, b - a - 1ll);
		if(sq * sq < ab) {
			if((sq + 1) * sq < ab) {
				ll t = (sq - a) * 2;
				ans += t;
				ans += t < len;
			//	de(1);
			} else {
				ll t = max(0ll, (sq - a - 1) * 2 + 1);
				//dd(sq), de(a);
				ans += t;
				ans += t < len;
		//		de(2);
			}
		} else {
			ll t = max(0ll, (sq - a - 1) * 2);
			ans += t;
			ans += t < len;
		//	de(3);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
1
314159265 358979323
*/