#include <stdio.h>

int main(){
	int A,B;
	scanf("%d %d",&A,&B);
	char str1[255];
	scanf("%s",str1);
	int ctr=0;
	
	for(int i=0; str1[i] != '\0'; i++){
		if(str1[A] != '-'){
			printf("No");
			return 0;
		}
		if(str1[i] >= '0'&&str1[i] <= '9'){
			ctr++;
		}
	}
	if(ctr==A+B){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
	return 0;
}