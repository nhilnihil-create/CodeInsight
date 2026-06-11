#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

int main(){
	ll n;
	cin >> n;
	
	vector<ll> d;
	for(ll i = 1; i * i <= n; ++i){
		if(n % i == 0){
			d.push_back(i);
			if(i * i != n){
				d.push_back(n / i);
			}
		}
	}
	
	ll ans = 0;
	for(int i = 0; i < d.size(); ++i){
		if(d[i] != 1 && n % (d[i] - 1) == n / (d[i] - 1)){
			ans += d[i] - 1;
		}
	}
	
	cout << ans << endl;
	return 0;
}

