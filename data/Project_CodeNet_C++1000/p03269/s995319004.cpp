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
int n;
int main(){
	scanf("%d", &n);
	vector<vector<int> > ans;
	int cover, m;
	for(cover = 0, m = 0; cover + (1 << m) < n; m++) {
		ans.pb({m, m + 1, 0});
		ans.pb({m, m + 1, 1 << m});
		cover += 1 << m;
	}
	for(int i = m; ~i; i--) {
		if(cover + (1 << i) < n) {
			ans.pb({i, m, cover + 1});	
			cover += (1 << i);
		}
	}
	printf("%d %d\n", m + 1, sz(ans));
	for(auto & it : ans)
		printf("%d %d %d\n", it[0] + 1, it[1] + 1, it[2]);
	return 0;
}
