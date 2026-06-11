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
vector<pii> ans;
char s[N];
int n;
bool check() {
	n = strlen(s);
	if(s[n - 1] == '1')
		return 0;
	if(s[0] != '1' || s[n - 2] != '1')
		return 0;
	int cnt = 0;
	for(int l = 0, r = n - 2; l <= r; l++, r--) {
		if(s[l] != s[r])
			return 0;
		cnt += s[l] == '1';
	}
	if(n & 1) {
		int p = 0;
		for(int i = 0; i < cnt; i++) {
			ans.pb({p, i * 2 + 1});
			p = i * 2 + 1;
		}
		p = 0;
		for(int i = 0; i < cnt; i++) {
			ans.pb({p, (i + 1) * 2});
			p = (i + 1) * 2;
		}
		int cur = cnt * 2 + 1;
		for(int l = cnt * 2, r = cnt * 2 - 1, i = 0, j = n - 2; i <= j; i++, j--) {
			if(s[i] == '1') {
				l -= 2;
				r -= 2;
				l = max(0, l);
				r = max(0, r);
			} else { 
				ans.pb({l, cur});
				ans.pb({r, cur + 1});
				cur += 2;
			}
		}
	} else {
		ans.pb({0, 1});
		rep(i, 0, cnt - 1)
			ans.pb({i * 2, (i + 1) * 2});
		rep(i, 0, cnt - 1)
			ans.pb({i * 2 + 1, (i + 1) * 2 + 1});
		int cur = cnt * 2;
		for(int l = (cnt - 1) * 2, r = (cnt - 1) * 2 + 1, i = 0, j = n - 2; i <= j; i++, j--) {
			if(s[i] == '1') {
				l -= 2;
				r -= 2;
				l = max(l, 0);
				r = max(r, 0);
			} else {
				ans.pb({l, cur});
				ans.pb({r, cur + 1});
				cur += 2;
			}
		}
	}
	return 1;
}
int main(){
	scanf("%s", s);
	if(!check()) puts("-1");
	else {
		for(auto & it : ans)
			printf("%d %d\n", it.fi + 1, it.se + 1);
	}
	return 0;
}
