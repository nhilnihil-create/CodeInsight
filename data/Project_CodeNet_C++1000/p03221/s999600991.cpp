#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> c[100005];
	REP(i,m){
		int p,y;
		cin >> p >> y;
		c[p].emplace_back(y, i);
	}
	vector<string> ans(m+1);
	REP(i,n){
		sort(c[i].begin(),c[i].end());
		rep(j, c[i].size()){
			int id = c[i][j].second;
			string s = to_string(i);
			string t = to_string(j+1);
			rep(k,6-s.size()){
				ans[id] += '0';
			}
			ans[id] += s;
			rep(k,6-t.size()){
				ans[id] += '0';
			}
			ans[id] += t;
		}
	}
	REP(i,m){
		cout << ans[i] << endl;
	}
    return 0;
}

