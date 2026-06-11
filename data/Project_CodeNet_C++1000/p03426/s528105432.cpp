#include<cstdlib>
#include<cstdio>

int main(){
	int H, W, D;
	scanf("%d %d %d", &H, &W, &D);
	int row[H*W], column[H*W];
	for (int i = 0; i < H; ++i)	{
		for (int j = 0; j < W; ++j)	{
			int tmp;
			scanf("%d", &tmp);
			tmp--;
			row[tmp] = i;
			column[tmp] = j;
		}
	}
	unsigned long long ruiseki[H*W];
	for (size_t i = 0; i < D; i++){
		ruiseki[i] = 0;
		for (size_t j = i + D; j < H*W; j+=D){
			ruiseki[j] = ruiseki[j - D] + abs(row[j] - row[j - D]) + abs(column[j] - column[j - D]);
		}
	}
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		unsigned l, r;
		scanf("%u %u", &l, &r);
		l--;r--;
		printf("%lld\n", ruiseki[r] - ruiseki[l]);
	}
	return 0;
}