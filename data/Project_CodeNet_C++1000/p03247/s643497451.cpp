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
const int N = 1010;
int n;
vi ans;
int x[N], y[N];
void gao(int x, int y) {
	vector<char> ret;
	for(int i = sz(ans) - 1; ~i; i--) {
		if(abs(x) > abs(y)) {
			ret.pb(x > 0 ? 'R' : 'L');
			x += (x > 0) ? -ans[i] : ans[i];
		} else {
			ret.pb(y > 0 ? 'U' : 'D');
			y += (y > 0) ? -ans[i] : ans[i]; 
		}
	}
	reverse(all(ret));
	for(auto & ch : ret)
		putchar(ch);
	puts("");
}
int main(){
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d%d", x + i, y + i);
	rep(i, 1, n) if(abs(x[i] + y[i]) % 2 != abs(x[i - 1] + y[i - 1]) % 2) {
		puts("-1");
		return 0;
	}
	if(abs(x[0] + y[0]) % 2) {
		rep(i, 0, 31)
			ans.pb(1 << i);	
	} else {
		ans.pb(1);
		rep(i, 0, 31)
			ans.pb(1 << i);
	}
	printf("%d\n", sz(ans));
	rep(i, 0, sz(ans)) printf("%d%c", ans[i], " \n"[i + 1 == sz(ans)]);
	rep(i, 0, n)
		gao(x[i], y[i]);
	return 0;
}
