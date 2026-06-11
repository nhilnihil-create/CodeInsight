#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7;
vector < int > nxt[_]; int mx , id , N;

void dfs(int x , int p , int d){
	if(mx < d){mx = d; id = x;}
	for(auto t : nxt[x]) if(t != p) dfs(t , x , d + 1);
}

int main(){
	cin >> N;
	for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	dfs(1 , 0 , 1); dfs(id , 0 , 1);
	cout << (mx % 3 == 2 ? "Second" : "First"); return 0;
}