#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int M, K;
	scanf("%d %d", &M, &K);
	
	if(K >= pow(2, M)) {
		printf("-1");
	} else if(M == 0) {
		printf("0 0");
	} else if(M == 1) {
		if(K == 1) printf("-1");
		else printf("0 0 1 1");
	} else {
		for(int i = 0; i < pow(2, M); i++) if(i != K) printf("%d ", i);
		printf("%d ", K);
		for(int i = pow(2, M)-1; i >= 0; i--) if(i != K) printf("%d ", i);
		printf("%d", K);
	}
	
	return 0;
}