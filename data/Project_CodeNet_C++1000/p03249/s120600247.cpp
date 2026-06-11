#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int cou[111111];

int main(){
	
	int n;cin >> n;
	vector<pair<ll,ll>> v;
	map<ll,ll> mp;
	REP(i,n){
		ll d;cin >> d;
		v.PB(MP(d,i+1));
		mp[d] = i+1;
	}
	
	sort(ALL(v),greater<pair<ll,ll>>());
	
	vector<pair<int,int>> ans;
	ll sum = 0;
	
	REP(i,n-1){
		ll mai = n - 2*(cou[v[i].SE]+1);
		//cout << v[i].FI << ' ' << mai << endl;
		if(!mp[v[i].FI - mai]){
			cout << -1 << endl;
			return 0;
		}
		ans.PB(MP(v[i].SE,mp[v[i].FI - mai]));
		cou[mp[v[i].FI - mai]] += cou[v[i].SE] + 1;
		sum += cou[v[i].SE] + 1;
	}
	
	if(sum != v[n-1].FI){
		cout << -1 << endl;
		return 0;
	}
	
	REP(i,ans.size()){
		cout << ans[i].FI << ' ' << ans[i].SE << endl;
	}
	return 0;
}
