#include <stdio.h>
#include <string.h>

int main(){
    
    int a, b;
    scanf("%d %d", &a, &b);
    int len = a + b + 1;
    char s[a+b+10];
    int count = 0;
    scanf("%s", s);
    
    if(strlen(s) != len){
    	printf("No\n");
    	// printf("1\n");
    	return 0;
	}
	else if(s[a] != '-'){
		printf("No\n");
		// printf("2\n");
		return 0;
	}
    for(int i = 0 ; i < len+5 ; i++){
    	if(s[i] == '-'){
    		count++;
		}
	}
    
    if(count > 1){
    	printf("No\n");
    	return 0;
	}
    
    printf("Yes\n");
    
    return 0;
}
