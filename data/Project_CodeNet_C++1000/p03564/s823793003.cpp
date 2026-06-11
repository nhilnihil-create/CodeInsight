#include<stdio.h>

int main(){
	
	
	int n, k;
	int ans = 1;
	
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++){
		if(ans <= k){
			ans *= 2;
		}else{
			ans += k;
		}
	}
	printf("%d", ans);
}