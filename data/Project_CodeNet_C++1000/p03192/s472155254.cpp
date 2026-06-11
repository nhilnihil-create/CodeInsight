#include<stdio.h>
#include<string.h>


int main(){
	
	char angka[1005];
	int count2;
	
	scanf("%s",angka);getchar();
	
	int len = strlen(angka);
	
	count2=0;
	for (int i=0;i<len;i++){
		
		if(angka[i]=='2'){
			count2++;		
		}
		
	}
	
	printf("%d\n",count2);
	
	return 0;	
}