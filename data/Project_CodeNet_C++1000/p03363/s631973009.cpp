#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	
	vector<ll> cumsum(n + 1, 0);
	rep(i, n){
		cumsum[i + 1] = cumsum[i] + a[i];
	}
	
	map<ll, ll> mp;
	rep(i, n + 1){
		mp[cumsum[i]]++;
	}
	
	ll ans = 0;
	for(auto itr : mp){
		ans += itr.second * (itr.second - 1) / 2;
	}
	
	cout << ans << endl;
	return 0;
}