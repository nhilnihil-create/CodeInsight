#include <stdio.h>

int main(){

	int n,a,b;
	int sum =0;
	
	scanf("%d %d %d",&n,&a,&b);
	
	for(int i=1;i<=n;i++){
		int x = 0;
		int idx = i;
		do{
			x += (idx%10);
			idx = idx / 10;
		}
		while(idx != 0);
		
		if(x >= a && x <= b){
		sum += i;
	}
}

	printf("%d",sum);
	

	
    return 0;
}