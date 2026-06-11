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

int main(){

	vector<pair<pair<int,int>,int>> ans;
	REP(i,13){
		ans.PB(MP(MP(i+1,i+2),0));
	}

	int n;cin >> n;n--;
	int now = 0;
	for(int i = 0;i < 13;i++){
		if(2 * now + 1 <= n){
			ans.PB(MP(MP(i+1,i+2),now+1));
			now = 2 * now + 1;
		}
		else{
			break;
		}
		if(((now + 1) / 2) * 3 - 1 <= n){
			ans.PB(MP(MP(i+1,i+2),now+1));
			now = ((now + 1) / 2) * 3 - 1;
		}
		else {
			break;
		}
	}

	while(now != n){
		int tmp = 1;
		int num = 1;
		while(now + 3*tmp < n){
			tmp *= 3;
			num++;
		}
		ans.PB(MP(MP(num,14),now+1));
		now += tmp;
	}

	cout << 14 << " " << ans.size() << endl;
	REP(i,ans.size())cout << ans[i].FI.FI << " " << ans[i].FI.SE << " " << ans[i].SE << endl;

	return 0;
}
