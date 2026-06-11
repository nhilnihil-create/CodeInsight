#include<cstdio>
int M,K;
int main() {
	scanf("%d %d",&M,&K);
	if(K>=(1<<M)) {
		printf("-1");
		return 0;
	}
	if(M==1) {
		if(K==0) printf("0 0 1 1");
		else printf("-1");
		return 0;
	}
	for(int i=0;i<(1<<M);i++) {
		if(i!=K) printf("%d ",i);
	}
	printf("%d ",K);
	for(int i=(1<<M)-1;i>=0;i--) {
		if(i!=K) printf("%d ",i);
	}
	printf("%d",K);
	return 0;
}
/*
1 偶  -> 0
1 奇  -> 1 

000
001
010
011
//100
101
110
111

00
01
00
01
0 1 0 1

0 1 2 3 5 6 7 4 7 6 5 3 2 1 0 4
*/