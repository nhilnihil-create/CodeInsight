#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, a, b;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	vector<ll> v;
	ll ans = 0;
	bool flag = true;
	rep(i, 0, n){
		cin >> a >> b;
		ans += a;
		if(a > b){
			v.push_back(b);
		}
		if(a != b){
			flag = false;
		}
	}
	sort(v.begin(), v.end());
	
	if(flag){
		print(0)
	}
	else{
		print(ans-v[0])
	}
	return 0;
}