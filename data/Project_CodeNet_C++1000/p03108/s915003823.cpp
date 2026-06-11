#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
static LL INF = (1LL<<62);

const int MAX = 100004;
int PARENT[MAX] = {0};
int RANK[MAX] = {0};
int CHLDS[MAX] = {0};

void init(int L){
	if(L<1) return;
	for(int i=0; i<L; i++){
		PARENT[i]=i; RANK[i]=0; CHLDS[i] = 1;
	}
}

int root(int x){
	if(x<0) return -1;
	if(PARENT[x]==x){
		return x;
	}
	else{
		int p = root(PARENT[x]);
		if(p != PARENT[x]){
			if(CHLDS[x] != 0){
				CHLDS[p] += CHLDS[x];
				CHLDS[x] = 0;
			}
			PARENT[x] = p;
		}
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
		CHLDS[a] += CHLDS[b]; CHLDS[b] = 0;
	}
	else{
		PARENT[a] = b;
		if(RANK[x]==RANK[y]) RANK[x] += RANK[y];
		CHLDS[b] += CHLDS[a]; CHLDS[a] = 0;
	}
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	vector<pair<int, int>> V;
	for(int i=0; i<M; i++){
		int a, b; cin >> a >> b; a--; b--;
		V.push_back(make_pair(a, b));
	}

	init(N);
	vector<LL> A;
	LL w = (N*(N-1))/2;
	A.push_back(w); 
	for(int i=V.size()-1; i>=0; i--){
		LL tmp = A[A.size()-1];
		auto br = V[i];
		int x = br.first;
		int y = br.second;
		int rx = root(x);
		int ry = root(y);
		LL ca = CHLDS[rx];
		LL cb = CHLDS[ry];
		if(same(rx, ry) != 1){
			tmp -= (ca*cb);
		}
		if(i > 0){
			A.push_back(tmp);
		}
		combine(x, y);
	}
	for(int i=A.size()-1; i>=0; i--) printf("%lld\n", A[i]);
	return 0;
}