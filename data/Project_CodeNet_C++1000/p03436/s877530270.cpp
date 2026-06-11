#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	vector<vector<vector<P>>> g(h, vector<vector<P>>(w, vector<P>(0)));
	vector<vector<int>> d(h, vector<int>(w, -1));
	int sum = 0;
	rep(i, h){
		cin >> s.at(i);
		rep(j, w) if(s.at(i).at(j) == '#') sum++;
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(i-1 >= 0) if(s.at(i-1).at(j  ) == '.') g.at(i).at(j).push_back({i-1, j  });
			if(i+1 <  h) if(s.at(i+1).at(j  ) == '.') g.at(i).at(j).push_back({i+1, j  });
			if(j-1 >= 0) if(s.at(i  ).at(j-1) == '.') g.at(i).at(j).push_back({i,   j-1});
			if(j+1 <  w) if(s.at(i  ).at(j+1) == '.') g.at(i).at(j).push_back({i,   j+1});
		}
	}
	queue<P> q;
	q.push({0, 0});
	d.at(0).at(0) = 0;
	while(!q.empty()){
		P za = q.front();
		int dis = d.at(za.first).at(za.second) + 1;
		rep(i, g.at(za.first).at(za.second).size()){
			int fst = g.at(za.first).at(za.second).at(i).first;
			int sec = g.at(za.first).at(za.second).at(i).second;
			if(d.at(fst).at(sec) == -1){
				q.push({fst, sec});
				d.at(fst).at(sec) = dis;
			}
		}
		q.pop();
	}
/*	rep(i, h){
		rep(j, w) cout << d.at(i).at(j) << ' ';
		cout << endl;
	}*/
	if(d.at(h-1).at(w-1) != -1){
		int ans = h*w - d.at(h-1).at(w-1) - sum - 1;
		cout << ans << endl;
	}else{
		cout << -1 << endl;
	}
	return 0;
}