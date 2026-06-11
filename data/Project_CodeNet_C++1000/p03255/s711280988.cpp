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
#define LLINF 1000000000000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
	
	ll n, x;
	cin >> n >> x;
	
	vector<ll> v(n+1);
	vector<ll> sum_v(n+1);
	REP(i,n){
		cin >> v[i+1];
		sum_v[i+1] = v[i+1];
	}
	
	REP(i,n)sum_v[i+1] += sum_v[i];
	
	ll ans = LLINF;
	for(int i = 1;i <= n;i++){
		ll now = 0;
		ll place = n;
		ll kosuu = 1;
		while(place > 0){
			now += (sum_v[place] - sum_v[max(place - i, 0LL)]) * max(5LL, 2*kosuu + 1);
			place -= i;
			kosuu++;
			if(ans < now)break;
		}
		now += (i + n) * x;
		ans = min(ans, now);
	}
	
	cout << ans << endl;
	
	return 0;
}