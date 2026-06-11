#include <stdio.h>
int main(){
	int a, b; 
	scanf("%d", &a);
	scanf("%d", &b);
	int ans=1;
	for (int i = 0; i<a; i++){
		if(ans<b){
			ans= ans*2;
		}else{
			ans= ans + b;
		}
	}
	printf("%d", ans);
	return 0;
}