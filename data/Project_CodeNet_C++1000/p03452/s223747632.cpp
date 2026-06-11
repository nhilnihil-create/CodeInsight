#include <iostream>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, l, r, d, pos[100008];
bool used[100008];
vector<ll> edge[100008];
map<pair<ll, ll>, ll> info;
string ans = "Yes";

void dfs(ll now){
	used[now] = true;
	for(ll i = 0; i < edge[now].size(); i++){
		ll next = edge[now][i];
		if(used[next]){
			if(pos[next]-pos[now] != info.at(make_pair(now, next))){ans = "No";}
		}
		else{
			pos[next] = pos[now] + info.at(make_pair(now, next));
			dfs(next);
		}
	}
}

int main(){
	cin >> n >> m;
	for(ll j = 1; j <= m; j++){
		cin >> l >> r >> d;
		edge[l].push_back(r);
		edge[r].push_back(l);
		info.insert(make_pair(make_pair(l, r), d));
		info.insert(make_pair(make_pair(r, l), -d));
	}
	
	memset(used, 0, sizeof(used));
	for(ll i = 1; i <= n; i++){
		if(!used[i]){
			pos[i] = 0;
			dfs(i);
		}
	}
	
	cout << ans << endl;
	return 0;
}