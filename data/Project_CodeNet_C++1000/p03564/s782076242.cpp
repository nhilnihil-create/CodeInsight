#include <stdio.h>

int main (){
	
	int n, k;
	scanf("%d %d", &n, &k);
	int z = 1;
	
for (int i = 0; i < n; i++) {
        if (2 * z <= z + k) {
            z *= 2;
        } else {
            z += k;
        }
    }
    printf("%d", z);
	
	
	return 0;
}