#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

int PARENT[100002] = {0};
int RANK[100002] = {0};

void init(int L){
	if(L<1) return;
	for(int i=0; i<L; i++){
		PARENT[i]=i;
		RANK[i]=0;
	}
}

int root(int x){
	if(x<0) return -1;
	if(PARENT[x]==x){
		return x;
	}
	else{
		PARENT[x] = root(PARENT[x]);
		return PARENT[x];
	}
}

int same(int x, int y){
	if(x==y) return 1;
	if(root(x)==root(y)){
		return 1;
	}
	else{
		return 0;
	}
}

void combine(int x, int y){
	if(x==y) return;

	int a = root(x);
	int b = root(y);
	if(a==b) return;

	if(RANK[x]<RANK[y]){
		PARENT[b] = a;
	}
	else{
		PARENT[a] = b;
		if(RANK[x]==RANK[y]) RANK[x] += RANK[y];
	}
}


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	init(N);
	for(int i=0; i<M; i++){
		int X, Y, Z;
		cin >> X >> Y >> Z;
		combine(X-1, Y-1);
	}
	map<int, int> mp;
	LL ans = 0;
	for(int i=0; i<N; i++){
		int u = root(i);
		if(mp.count(u) == 0){
			ans++;
			mp[u] = 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
