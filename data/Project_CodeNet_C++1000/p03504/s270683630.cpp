#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define vcout(v) rep(i,v.size()) cout << v[i] << " "; cout << endl
#define mcout(m) rep(j,m.size()){vcout(m[j]);}
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
const ll MOD = 1e9 + 7;

void mainsolve(){

	ll n,c;
	cin >> n >> c;
	vector<vector<bool>> memo(c,vector<bool>(1e5, false));

	rep(i,n){
		ll s,t,cc;
		cin >> s >> t >> cc;
		--s; --t; --cc;

		for(ll j = s; j <= t; j++) memo[cc][j] = true;
	}

	ll res = 0;
	rep(i,1e5){
		ll cnt = 0;
		rep(j,c){
			if(memo[j][i]) cnt++;
		}

		res = max(res, cnt);
	}

	cout << res << endl;

	return;
}

int main(){
	
	//ll TC;cin>>TC;rep(I,TC){cout<<"case:"<<I+1<<"---"<<endl; // comment out!
		mainsolve();
	//} // comment out!
	return 0;
}