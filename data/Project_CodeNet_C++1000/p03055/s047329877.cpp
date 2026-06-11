#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int N, ai, bi;
vector <int> g[MAXN];

int calc(int u, int parent, int &d){
	int depth = 0;
	for(int v : g[u]){
		if(v == parent)continue;
		
		int cdepth = calc(v, u, d) + 1;
		d = max(d, depth + cdepth + 1);
		depth = max(depth, cdepth);
	}
	return depth;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N - 1; i++){
		scanf("%d %d", &ai, &bi);
		ai--, bi--;
		
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	
	int d = 0;
	calc(0, -1, d);
	
	if(d % 3 == 2)printf("Second\n");
	else printf("First\n");
	
	return 0;
}	
