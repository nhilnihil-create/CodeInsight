#include <stdio.h>
int main(){
	
	int a,b;
	char str[15];
	
	scanf("%d %d %s" , &a, &b, &str);
	
	for(int i = 0 ; i < a ; i++){
		if(str[i] != '-'){
			continue;
		}
		else{
			printf("No");
			return 0;
		}	
	}
	for(int i = a+1 ; i <= a+b ; i++){
		if(str[i] != '-'){
			continue;
		}
		else{
			printf("No");
			return 0;
		}
		
	}
	if(str[a] == '-'){
		
		printf("Yes");
	}
	else{
		printf("No");
	}
	
	return 0;
}