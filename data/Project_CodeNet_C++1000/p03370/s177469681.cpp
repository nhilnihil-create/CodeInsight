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
	int n, x; cin >> n >> x;
	int m[105];
	int sum = 0;
	rep(i, 0, n){
		cin >> m[i];
		sum += m[i];
	}
	int ans = n;
	x -= sum;
	sort(m, m+n);
	ans += x/m[0];
	cout << ans << endl;
	return 0;
}