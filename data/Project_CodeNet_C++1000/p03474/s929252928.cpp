#include <stdio.h>
#include <string.h>

int main(){
	int a, b, i;
	scanf("%d %d", &a, &b);
	char str[100];
	scanf("%s", str);
	if(str[a] == '-'){
		for(i = 0;i < a + b + 1;i++){
			
			if(str[i] < 48 || str[i] > 57){
				if(i == a){
					continue;
				}
				printf("No");
				break;
			}
			}
		}
	else{
		printf("No");
    }
	if(i == a + b + 1){
	if(strlen(str) == a + b + 1){
		printf("Yes");
	}else{
		printf("No");
	}
	}
	
	
	return 0;
}