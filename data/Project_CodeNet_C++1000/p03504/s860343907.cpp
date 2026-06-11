#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	ll n,C;cin>>n>>C;
	ll x,y,z;
	vector<vector<ll>> a(C + 1,vector<ll>(100001,0LL));
	vector<vector<ll>> v(C + 1,vector<ll>(100001,0LL));
	for(int i = 0; i < n; i++) {
		cin>>x>>y>>z;
		a[z][x] += 1;
		a[z][y+1] -= 1;
	}
	for(int i = 1; i <= C; i++) {
		for(int j = 0; j < a[i].size() - 1; j++) {
			v[i][j + 1] = v[i][j] + a[i][j + 1];
			// if (v[i][j + 1] > 1){
			// 	v[i][j + 1] = 1;
			// } 
		}
	}
	int res = 0;
	for(int j = 1; j < 100001; j++) {
		int ans = 0;
		for(int i = 1; i <= C; i++) {
			if (v[i][j] >0){
				ans++;
			}
		}
		res = max(res,ans);
	}
	// for(auto i = a.begin(); i != a.end(); i++) {
	// 	cout << i->fs <<" " << i->sc.fs <<" " << i->sc.sc << endl;
	// }
	cout << res << endl;
	return 0;
}
