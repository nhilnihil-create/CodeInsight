#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

ll s[2][100001];
int a[2], q;
ll mn(ll x, int p) {
	int i = lower_bound(s[p],s[p]+a[p], x) - s[p];
	ll ans = 1e18;
	if(i>0) ans = min(ans, abs(x-s[p][i-1]));
	if(i<a[p]) ans = min(ans, abs(x-s[p][i]));
	return ans;
}
int main()
{
	cin >> a[0] >> a[1] >> q;

	for(int i = 0; i < a[0]; i++) cin >> s[0][i];
	for(int i = 0; i < a[1]; i++) cin >> s[1][i];
	for(int i = 0; i <q; i++){
		ll x;
		cin >> x;
		ll ans = 1e18;
		for(int p = 0; p < 2; p++){
			int j = lower_bound(s[p],s[p]+a[p], x)-s[p];
			if(j > 0) ans =min(ans, abs(x-s[p][j-1]) +mn(s[p][j-1],p^1));
			if(j < a[p]) ans =min(ans, abs(x-s[p][j]) +mn(s[p][j],p^1));
		}
		cout << ans << endl;
	}

}
