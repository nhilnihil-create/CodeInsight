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
#define SHOW1d(v,n) {for(int WWW = 0;WWW < (n);WWW++)cerr << v[WWW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
	
	vector<ll> v;
	
	for(ll i = 1;i <= 1000;i++){
		ll kake = 1;
		ll kyuu = 0;
		while(i * kake + kyuu < 10000000000000000){
			v.PB(i * kake + kyuu);
			kake *= 10;
			kyuu *= 10;
			kyuu += 9;
		}
	}
	
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	
	vector<double> cost;
	
	REP(i,v.size()){
		ll tmp = v[i];
		ll cou = 0;
		while(tmp){
			cou += tmp % 10;
			tmp /= 10;
		}
		cost.PB((double)v[i]/(double)cou);
	}
	
	int k;cin >> k;
	
	int cou = 0;
	REP(i,v.size()){
		bool flag = true;
		for(ll j = i + 1;j < min(i+1000,(ll)v.size());j++){
			if(cost[i] > cost[j]){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << v[i] << endl;
			cou++;
		}
		if(cou == k)break;
	}
	
	return 0;
}
