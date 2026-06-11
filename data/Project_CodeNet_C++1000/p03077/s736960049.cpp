#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, a, b, c, d, e;
	cin >> n >> a >> b >> c >> d >> e;
	ll mi = min({a,b,c,d,e});
	ll ans = (n + mi - 1) / mi + 4;
	cout << ans << endl;
	return 0;
}