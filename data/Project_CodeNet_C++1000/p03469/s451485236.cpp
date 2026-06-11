#include <stdio.h>

int main(){
	
	char str[15];
	scanf("%s",&str);
	for(int i = 0; i<10;i++){
		if(i==3){
			printf("8");
		}
		else printf("%c",str[i]);
	}

	
	return 0;
}