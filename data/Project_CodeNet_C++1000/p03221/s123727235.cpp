#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
const int MAX_N = 1e5+10;

int main() {
	int n,m; cin>>n>>m;
	vector<int> p(MAX_N), y(MAX_N);
	vector<vector<int>> yd(MAX_N);
	rep(i,m){
		cin>>p[i]>>y[i];
		p[i]--;
		yd[p[i]].push_back(y[i]);
	}
	rep(i,n) sort(yd[i].begin(),yd[i].end());
	rep(i,m){
		vector<int> pp=yd[p[i]];
		int num=lower_bound(pp.begin(), pp.end(), y[i])-pp.begin();
		printf("%06d%06d\n", p[i]+1, num+1);
	}
}