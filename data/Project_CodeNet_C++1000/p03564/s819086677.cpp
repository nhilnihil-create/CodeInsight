#pragma target("avx")
#pragma optimize("O3")
#include<stdio.h>
int main(){
	int n, k, x=1;
	scanf("%d%d", &n, &k);
	while(n--){
		if(x<k) x += x;
		else x += k;
	}
	printf("%d", x);
	return 0;
}

