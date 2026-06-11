#include <stdio.h>

int main(){
	int a, b, ans = 1, j = 2, i;
	scanf("%d %d" , &a, &b);
	
	for(i = 0; i < a;i++){
		if(ans < b){
			ans = 1;
			ans = ans * j;
			j *= 2;
		}else{
			ans += b;
		}
	}

	printf("%d", ans);
	
	
	return 0;
}