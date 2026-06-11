#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int n,m;
	cin >> n >> m;

	vector<pair<int, int>> pa;
	vector<vector<pair<int, int>>> c(n);
	for(int i=0; i<m; i++){
		int p,y;
		cin >> p >> y;
		p--;
		y--;
		pa.emplace_back(p,y);
		c[p].emplace_back(y,i);
	}

	for(int i=0; i<n; i++){
		sort(c[i].begin(), c[i].end());
		for(int j=0; j<c[i].size(); j++){
			pa[c[i][j].second].second = j;
		}
	}

	for(int i=0; i<m; i++){
		cout << setw(6) <<setfill('0') << pa[i].first+1 << setw(6) << setfill('0') << pa[i].second+1 << endl;
	}

	return 0;
}