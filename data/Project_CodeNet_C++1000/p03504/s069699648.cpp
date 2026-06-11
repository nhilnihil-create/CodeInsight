#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	int n,c;
	cin >> n >> c;
	vector<pair<int,int>> vpi[c+10];
	vector<vector<int>> tv(c+20,vector<int>(100010,0));
	rep(i,n){
		int s,t,cc;
		cin >> s >> t >> cc;
		vpi[cc].push_back({s,t});
	}
	rep(i,c+10){
		sort(vpi[i].begin(),vpi[i].end());
	}
	rep(cc,c+10){
		for(auto u : vpi[cc]){
			int s = u.first, t = u.second;
			if(tv[cc][s]==-1) tv[cc][s] = 0;
			else tv[cc][s] = 1;
     		tv[cc][t] = -1;
		}
	}
	int ans = 0;
	int now = 0;
	rep(i,100010){ 
		rep(j,c+10){
			if(tv[j][i]==1) now++; 
		}
		ans = max(ans,now);
		rep(j,c+10){
			if(tv[j][i]==-1) now--; 
		}
	}
	cout << ans << endl;
	return 0;
}
