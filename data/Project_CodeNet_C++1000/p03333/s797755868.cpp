#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
	int n;cin >> n;
	vector<ll> L(n+1);
	vector<ll> R(n+1);
	
	REP(i,n)cin >> L[i] >> R[i];
	
	sort(ALL(R));
	sort(ALL(L),greater<ll>());
	
	DBG(SHOW1d(R,R.size()););
	DBG(SHOW1d(L,L.size()););
	
	ll ans = 0;
	ll tmp = 0;
	REP(i,n+1){
		tmp += 2 *(L[i] - R[i]);
		ans = max(ans,tmp);
	}
	
	cout << ans << endl;
	return 0;
}