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

int main()
{
	ll n, m;	
	cin >> n >> m;	
	vector<ll> x(n), y(n), z(n);
	ll ans = -1e17;

	rep(i,n) cin >> x[i] >> y[i] >> z[i];

	for(ll tmp = 0; tmp < (1 << 3); tmp++){
		bitset<3> bit(tmp); 
		vector<pair<ll,ll>> value(0);

		rep(i,n){
			ll now = 0;
			if(bit.test(0)){ //bitが立っている時、x[i]がそのままスコアになる。
				now += x[i];
			} else {
				now += -x[i];
			}
			if(bit.test(1)){
				now += y[i];
			} else {
				now += -y[i];
			}
			if(bit.test(2)){
				now += z[i];
			} else {
				now += -z[i];
			}
			value.push_back({now,i});
		}

		// valueの大きい方からM個取る
		sort(value.rbegin(),value.rend());
		ll x_sum = 0, y_sum = 0, z_sum = 0;
		ll ret = 0;
		rep(i,m){
			ret += value[i].first;
			x_sum += x[value[i].second];
			y_sum += y[value[i].second];
			z_sum += z[value[i].second];
		}
		if(bit.test(0)){
			if(x_sum >= 0) {
				// ok 
			} else {
				continue;
			}
		}
		if(bit.test(1)){
			if(y_sum >= 0) {
				// ok 
			} else {
				continue;
			}
		}
		if(bit.test(2)){
			if(z_sum >= 0) {
				// ok 
			} else {
				continue;
			}
		}
		ans = max(ans,ret);
	}
	cout << ans << endl;
}
