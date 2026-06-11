#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

ll mp[222222];

set<pair<ll,ll>> s;
vector<pair<ll,ll>> v;


int main(){
	
	ll h,w,n;cin >> h >> w >> n;
	REP(i,n){
		ll a,b;cin >> a >> b;
		v.PB(MP(a,b));
		s.insert(MP(a, b));
	}
	
	mp[1] = 1;
	ll tmp = 1;
	for(ll i = 2;i < 222222;i++) {
		tmp++;
		for(ll j = tmp;j < 222222;j++){
			if(s.count(MP(j,i))){
				tmp = j + 1;
			}
			else {
				break;
			}
		}
		mp[i] = tmp;
	}
	
	SHOW1d(mp,11);
	
	ll ans = h;
	REP(i,n){
		if(v[i].FI > mp[v[i].SE]){
			ans = min(ans, v[i].FI - 1);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
