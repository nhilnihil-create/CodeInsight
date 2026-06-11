#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), l(n), r(n);
	rep(i,n) cin >> a[i];
	l[0] = a[0];
	r[n-1] = a[n-1];
	rep(i,n-1) l[i+1] = gcd(l[i], a[i+1]);
	for(int i = n-2; i >= 0; --i) r[i] = gcd(r[i+1], a[i]);
	int ans = 1;
	rep(i,n){
		if(i == 0) chmax(ans, r[1]);
		else if(i == n-1) chmax(ans, l[n-2]);
		else chmax(ans, (int)(gcd(l[i-1], r[i+1])));
	}
	cout << ans << endl;
	return 0;
}