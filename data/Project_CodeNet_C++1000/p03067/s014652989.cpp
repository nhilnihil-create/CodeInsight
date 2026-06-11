#include<stdio.h>
int main(void){
	int a, b, c;
  	scanf("%d %d %d", &a, &b, &c);
  	if((a < c && c < b) || (b < c && c < a)){
    	printf("Yes\n");
    }else{
    	printf("No\n");
    }
  	return 0;
}