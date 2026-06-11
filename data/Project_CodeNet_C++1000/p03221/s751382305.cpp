#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,i,j;
	cin >> n >> m;
	vector<vector<pair<int,int>>> a(n+1,vector<pair<int,int>>(0));
	
	int p,y;
	for(i=0; i<m; i++){
		cin >> p >> y;
		a[p].push_back({y,i});
	}
	
	for(i=1; i<=n; i++){
		sort(a[i].begin(),a[i].end());
	}
	
	vector<pair<int,int>> ans(m);
	
	for(i=1; i<=n; i++){
		for(j=0; j<a[i].size(); j++){
			ans[a[i][j].second].first=i;
			ans[a[i][j].second].second=j+1;
		}
	}
	
	for(i=0; i<m; i++){
		printf("%06d%06d\n",ans[i].first,ans[i].second);
	}
	return 0;
}