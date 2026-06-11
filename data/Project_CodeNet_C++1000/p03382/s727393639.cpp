#include <bits/stdc++.h>

using namespace std;

#define DBG cerr << '!' << endl;
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
#define Decimal fixed<<setprecision(10)
#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int main()
{
	int n;cin >> n;
	vector<int> v(n);
	for(int i = 0;i < n;i++)cin >> v[i];
	sort(v.begin(),v.end());
	int ans = -1;
	
	for(int i = 0;i < n;i++){
		if(max(v[i],v[v.size()-1]-v[i]) < max(ans,v[v.size()-1]-ans)){
			ans = v[i];
		}
	}
	cout << v[v.size()-1] << ' ' << ans << endl;
	
	return 0;
}