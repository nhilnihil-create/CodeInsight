#include<cstdio>
const static int MAX_N = 500;
int imos[MAX_N][MAX_N];

int main(){
	unsigned N, M, Q;
	scanf("%u %u %u", &N, &M, &Q);
	for (unsigned i = 0; i < M; i++){
		unsigned l, r;
		scanf("%u %u", &l, &r);
		r--;
		imos[0][r]++;
		imos[l][r]--;
	}
	for (unsigned i = 1; i < N; i++){
		for (unsigned j = 0; j < N; j++){
			imos[i][j] += imos[i-1][j];
		}
	}
	for (unsigned i = 0; i < N; i++){
		for (unsigned j = 1; j < N; j++){
			imos[i][j] += imos[i][j-1];
		}
	}
	for (unsigned i = 0; i < Q; i++){
		unsigned p, q;
		scanf("%u %u", &p, &q);
		printf("%d\n", imos[p-1][q-1]);
	}
	return 0;
}