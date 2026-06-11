#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}
ll LCM(ll x, ll y){
	return x/GCD(x, y)*y;
}

int main() {
	int n, m, c; cin >> n >> m >> c;
	int b[30];
	rep(i, 0, m) cin >> b[i];
	int a[30][30];
	rep(i, 0, n){
		rep(j, 0, m) cin >> a[i][j];
	}
	int ans = 0;
	rep(i, 0, n){
		int val = c;
		rep(j, 0, m){
			val += a[i][j]*b[j];
		}
		if(val>0) ans++;
	}
	cout << ans << endl;
	return 0;
}