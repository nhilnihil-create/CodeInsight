#include <stdio.h>

int main() {
	int n,k;
	scanf("%d %d", &n, &k);
	int more = 1;
	while (more < k && n > 0){
		more *= 2;
		n--;
	}
	for(int i = 0; i < n; i++){
		more += k;
	}
	printf("%d\n", more);
	return 0;
}
