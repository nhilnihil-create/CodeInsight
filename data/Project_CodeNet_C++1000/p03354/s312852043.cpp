#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long long LL;
static LL INF = (1LL<<62);

const int MAX = 100002;
int PARENT[MAX] = {0};
int RANK[MAX] = {0};

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

	int N, M; cin >> N >> M;
	vector<int> P;
	for(int i=0; i<N; i++){
		int p; cin >> p;
		P.push_back(p-1);
	}

	init(N);
	for(int i=0; i<M; i++){
		int x, y; cin >> x >> y;
		combine(x-1, y-1);
	}
	for(int i=0; i<N; i++){
		root(i);
	}
	int ans = 0;
	for(int i=0; i<N; i++){
		if(same(i, P[i]) == 1){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
