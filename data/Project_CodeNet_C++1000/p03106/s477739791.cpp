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
	int a, b, k; cin >> a >> b >> k;
	int cnt = 0;
	for(int i=100;i>=0;i--){
		if(a%i==0 && b%i==0){
			cnt++;
		}
		if(cnt==k){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}