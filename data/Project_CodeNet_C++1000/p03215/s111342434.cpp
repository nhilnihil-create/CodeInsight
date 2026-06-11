#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;

ll n, k, a[1008];

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> k;
	rep(i, 1, n){cin >> a[i];}
	a[0] = 0LL;
	rep(i, 1, n){a[i] += a[i-1];}
	
	vector<ll> v;
	rep(i, 1, n){
		rep(j, i, n){
			v.push_back(a[j]-a[i-1]);
		}
	}
	ll ans = 0LL;
	rrep(b, 40, 0){
		ll bit = (1LL << b);
		ll cnt = 0;
		vector<ll> u;
		for(ll i = 0; i < v.size(); i++){
			if((v[i] & bit) == bit){
				cnt++;
				u.push_back(v[i]);
			}
		}
		if(cnt >= k){
			ans += bit;
			v.swap(u);
		}
	}
	print(ans)
	return 0;
}