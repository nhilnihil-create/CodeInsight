#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

double snk(ll x){
	ll tmp = x;
	ll denom = 0;
	while(tmp){
		denom += tmp%10;
		tmp /= 10;
	}
	return (double)x/denom;
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	set<ll> st;
	
	zep(i, 0, 14){
		ll nine = pow(10, i)-1;
		rep(j, 1, 999){
			st.insert(j*pow(10, i)+nine);
		}
	}
	
	vector<ll> ans;
	double mx = INF;
	for(auto it = st.rbegin(); it != st.rend(); it++){
		if(snk(*it) <= mx){
			ans.push_back(*it);
			mx = snk(*it);
		}
	}
	reverse(ans.begin(), ans.end());
	
	ll k;
	cin >> k;
	zep(i, 0, k){
		print(ans[i])
	}
	return 0;
}