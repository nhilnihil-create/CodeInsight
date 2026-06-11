#include <stdio.h>

int main(){
	
	int n,a,b;
	
	scanf("%d %d %d",&n,&a,&b);
	int sum =0;
	for(int i=1 ; i<=n;i++){
		if((i/10000)+((i/1000)%10)+((i/100)%10)+((i/10)%10)+(i%10)>=a&&((i/10000)+((i/1000)%10)+((i/100)%10)+((i/10)%10)+(i%10))<=b){
			sum +=i;
		}
	}
	printf("%d",sum);
	return 0;
}