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
	int n, m, x; cin >> n >> m >> x;
	map<int ,int> mp;
	rep(i, 1, m+1){
		int a; cin >> a;
		mp[a]++;
	}
	int left = 0;
	int right = 0;
	rep(i, 0, x) left += mp[i];
	rep(i, x, n+1) right += mp[i];
	cout << min(left, right) << endl;
	return 0;
}