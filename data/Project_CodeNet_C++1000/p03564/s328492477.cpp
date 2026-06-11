#include <stdio.h>

int main(){
	int awal = 1;
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i<n; i++){
		awal*2 > awal+k ? awal+=k : awal*=2;
	}
	printf("%d", awal);
	return 0;
}