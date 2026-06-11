#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;

int main(){
	string s;
	int x[2];
	cin >> s >> x[0] >> x[1];
	int p, dir, dist;
	p = 0;
	for(; p < s.size() && s[p] != 'T'; ++p) {
		x[0]--;
	}
	vector<int> dx[2];
	dist = dir = 0;
	for(; p < s.size(); ++p) {
		if (s[p] == 'T') {
			dx[dir].push_back(dist);
			dir = !dir;
			dist = 0;
		}
		else {
			dist++;
		}
	}
	if(dist) {
		dx[dir].push_back(dist);
	}

	set<int> dp[2][2];
	for(int k = 0; k < 2; ++k) {
		dp[k][0].insert(0);
		for(int i = 0; i < dx[k].size(); ++i) {
			dp[k][(i + 1) % 2].clear();
			EACH(j, dp[k][i % 2]) {
				dp[k][(i + 1) % 2].insert(*j + dx[k][i]);
				dp[k][(i + 1) % 2].insert(*j - dx[k][i]);
			}
		}
		/*
		EACH(i, dp[k][dx[k].size() % 2]){
			cout << *i << "," << endl;
		}
		cout << endl;
		*/
		if(dp[k][dx[k].size() % 2].find(x[k]) == dp[k][dx[k].size() % 2].end()) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}
