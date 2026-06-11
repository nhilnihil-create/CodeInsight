#include<bits/stdc++.h>
using namespace std;

long long N, M, color[100000];
vector<int> G[100000];

bool dfs(int now, int c){
	color[now] = c;
	for(int i=0; i<G[now].size(); i++){
		if(color[G[now][i]] == c) return false;
		if(color[G[now][i]] == 0 && !dfs(G[now][i], -c)) return false;
	}
	return true;
}

int main(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	long long p = 0;
	if(dfs(0, 1)){
		for(int i=0; i<N; i++){
			if(color[i] == 1) p++;
		}
		cout << p*(N-p) - M << endl;
	}else{
		cout << N*(N-1)/2 - M << endl;
	}
	return 0;
}