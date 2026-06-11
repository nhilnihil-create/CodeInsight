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
const int N = 8080;
char s[N];
int a, b;
bitset<N * 2> x, y, f, g;
int main(){
	scanf("%s", s);
	scanf("%d%d", &a, &b);
	int n = strlen(s), m = 0, cur = 0;
	vi st[2];
	rep(i, 0, n) {
		if(s[i] == 'T') {
			st[cur].pb(m);
			cur ^= 1;
			m = 0;
		} else m++;
	}
	if(m) st[cur].pb(m);
	x[N] = y[N] = 1;
	for(int i = 0; i < sz(st[0]); i++) {
		int it = st[0][i];
		if(i == 0) {
			f = x << it;
		} else {
			f = x >> it;
			f |= x << it;
		}
		swap(x, f);
	}
	for(auto it : st[1]) {
		g = y >> it;
		g |= y << it;
		swap(y, g);
	}
	puts((x[a + N] && y[b + N]) ? "Yes" : "No");
	return 0;
}
