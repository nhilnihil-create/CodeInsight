#include <bits/stdc++.h>
using namespace std;
const int maxn = 200200;
int alive[maxn], tot[2][maxn];
vector<int> e[maxn];
int main(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	for(auto & c : s) c -= 'A';
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y; x--; y--;
		e[x].push_back(y);
		e[y].push_back(x);
		tot[s[x]][y]++;
		tot[s[y]][x]++;
	}
	auto getVal = [&](int x){
		int ans = 0;
		if(tot[0][x] > 0) ans += 1;
		if(tot[1][x] > 0) ans += 2;
		return ans;
	};
	set<pair<int,int> > nodes;
	for(int i = 0; i < n; i++){
		alive[i] = 1;
		nodes.insert({getVal(i), i});
	}
	while(!nodes.empty()){
		auto v = *nodes.begin(); nodes.erase(nodes.begin());
		if(v.first == 3) {
			nodes.insert(v);
			break;
		}
		alive[v.second] = 0;
		for(auto nxt : e[v.second]){
			if(alive[nxt]){
				nodes.erase({getVal(nxt), nxt});
				tot[s[v.second]][nxt]--;
				nodes.insert({getVal(nxt), nxt});
			}
		}
	}
	if(nodes.empty()) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
