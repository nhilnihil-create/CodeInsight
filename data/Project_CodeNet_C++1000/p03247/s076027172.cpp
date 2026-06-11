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

ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};
string str = "LDRU";

int main(){
	int n;cin >> n;
	
	vector<pair<ll,ll>> v;
	bool parity[2] = {};
	
	REP(i,n){
		ll a,b;cin >> a >> b;
		parity[(a+b)%2] = true;
		v.PB(MP(a,b));
	}
	
	if(parity[0] & parity[1]){
		cout << -1 << endl;
		return 0;
	}
	
	vector<ll> ans;
	ll sum = 0;
	for(int i = 35;i >= 0;i--){
		ans.PB(1LL << i);
		sum += (1LL << i);
	}
	if(parity[0]){
		ans.PB(1);
		sum++;
	}
	
	cout << ans.size() << endl;
	REP(i,ans.size()){
		cout << ans[i];
		if(i != ans.size()-1)cout << ' ';
	}
	cout << endl;
		
	REP(i,n){
		ll x = v[i].FI;
		ll y = v[i].SE;
		ll nsum = sum;
		REP(j,ans.size()){
			nsum -= ans[j];
			REP(k,4){
				ll nx = x + dx[k] * ans[j];
				ll ny = y + dy[k] * ans[j];
				
				if(abs(nx) + abs(ny) <= nsum){
					x = nx;
					y = ny;
					cout << str[k];
					break;
				}
			}
		}
		cout << endl;
	}
	
	return 0;
}
