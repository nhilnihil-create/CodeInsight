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
#define LLINF 1000000000000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

pair<ll,ll> L[222222];
pair<ll,ll> R[222222];

int main(){
	
	int n;cin >> n;
	
	vector<ll> v(n);
	vector<ll> sv(n);
	
	REP(i,n){
		cin >> v[i];
		sv[i] = v[i];
	}
	
	REP(i,n-1)sv[i+1] += sv[i];
	
	ll now_s = v[0];
	ll now_p = 0;
	for(ll i = 1;i < n;i++){
		while(now_p < i-1 && abs(2*now_s-sv[i]) > abs(2*(now_s+v[now_p+1]) - sv[i])){
			now_p++;
			now_s += v[now_p];
		}
		L[i] = MP(now_s,sv[i] - now_s);
	}
	
	now_p = n-1;
	now_s = v[n-1];
	
	for(ll i = n-2;i > 0;i--){
		while(now_p > i+1 && abs(2*now_s-(sv[n-1]-sv[i-1])) > abs(2*(now_s+v[now_p-1]) - (sv[n-1]-sv[i-1]))){
			now_p--;
			now_s += v[now_p];
		}
		R[i] = MP(now_s,(sv[n-1] - sv[i-1]) - now_s);
	}
	
	ll ans = LLINF;
	
	for(int i = 1;i < n-2;i++){
		ll ma = max(max(L[i].FI,L[i].SE),max(R[i+1].FI,R[i+1].SE));
		ll mi = min(min(L[i].FI,L[i].SE),min(R[i+1].FI,R[i+1].SE));
		ans = min(ans,ma - mi);
	}
	
	cout << ans << endl;
	
	return 0;
}