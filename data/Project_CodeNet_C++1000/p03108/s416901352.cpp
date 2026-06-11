#include<cstdio>
using ll = long long;
using ull = unsigned long long;
const static int MAX_N = 100000;

unsigned par[MAX_N], rank[MAX_N], group_size[MAX_N];

void Init_union_find(unsigned n){
	for (unsigned i = 0; i < n; ++i){
		par[i] = i;
		rank[i] = 0;
		group_size[i] = 1;
	}
}

unsigned Find(unsigned x){
	if(par[x] == x) return x;
	else return par[x] = Find(par[x]);
}

void Unite(unsigned x, unsigned y){
	x = Find(x);
	y = Find(y);
	if(x == y) return;
	if(rank[x] < rank[y]){
		par[x] = y;
		group_size[y] += group_size[x];
	}else{
		par[y] = x;
		group_size[x] += group_size[y];
		if(rank[x] == rank[y]) rank[x]++;
	}
}

bool Same(unsigned x, unsigned y){
	return Find(x) == Find(y);
}

int main(){
    ull N, M;
    scanf("%llu %llu", &N, &M);
    unsigned A[M], B[M];
    for(unsigned i = 0; i < M; ++i){
        scanf("%u %u", A + i, B + i);
        A[i]--;B[i]--;
    }
    ull inconvenience[M];
    inconvenience[M-1] = N*(N - 1) >> 1;
    Init_union_find(N);
    for (int i = M - 2; i >= 0; i--){
        inconvenience[i] = inconvenience[i+1];
        if(!Same(A[i+1], B[i+1])){
            inconvenience[i] -= group_size[Find(A[i+1])]*group_size[Find(B[i+1])];
            Unite(A[i+1], B[i+1]);
        }
    }
    for (size_t i = 0; i < M; i++){
        printf("%llu\n", inconvenience[i]);
    }
	return 0;
}