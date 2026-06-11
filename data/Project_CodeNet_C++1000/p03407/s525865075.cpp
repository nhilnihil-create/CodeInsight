#include<stdio.h>

int main(){
	
	int a,b,c;
	
	scanf("%d %d %d",&a,&b,&c);
	
	int total = a +b ;
	
	if(total < c){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
	
	return 0;
	
}