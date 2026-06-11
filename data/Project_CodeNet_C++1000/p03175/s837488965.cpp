#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define int ll

typedef pair<int,int> pi;
typedef vector<int> vi;
 
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back

template<typename T> void max_self(T &a, T b) { a = max(a,b); return;}
template<typename T> void min_self(T &a, T b) { a = min(a,b); return;}
 
const int nax = 1e5 + 5;
const int mod = 1e9 + 7;

int solve(int a,int b,int c){
	
	a = a % c;	
	if(b == 0) return 1;
	else if((b % 2) == 0) return solve((a * a) % c,b / 2,c) % c;
	else return (a * solve((a * a) % c,b / 2,c) % c) % c;
}

int n;
vector<int> adj[nax];

pair<int,int> dfs(int index,int par){
	
	if(index != 1 && adj[index].size() == 1){
		pair<int,int> ans;
		ans.first = 2;
		ans.second = 1;
		return ans;
	}
	
	pair<int,int> ans = {1,1};
	for(auto u : adj[index]){
		if(u == par) continue;
		pair<int,int> temp = dfs(u,index);
		ans.first = (ans.first * temp.first) % mod;
		ans.second = (ans.second * temp.second) % mod;
	}
	
	ans.first = (ans.first + ans.second) % mod;
	ans.second = (ans.first - ans.second + mod) % mod;
	return ans;
}

signed main(){
	
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while(t--){
		cin >> n;
			
		int x,y;
		for(int i = 0; i < n - 1; ++i){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		if(n == 1) cout << "2";
		else cout << dfs(1,-1).first;	
	}
	
	return 0;
}
