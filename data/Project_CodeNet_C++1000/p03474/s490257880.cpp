#include<stdio.h>
#include<string.h>

int main(){
    
    int a, b, counter;
	char postal[100];
	
	scanf("%d %d", &a, &b);
	scanf("%s", postal);
	
	for(int i = 0; i < a; i++){
		if(postal[i]>='0'&&postal[i]<='9'){
			counter++;
		}
	}
	for(int i = a + 1; i<a+b+1; i++){
		if(postal[i]>='0'&&postal[i]<='9'){
		counter++;
		}
	}
	if(postal[a]=='-'){
		counter++;
	}
	
	if(counter==a+b+1){
		printf("Yes");
	}else{
		printf("No");
	}
	}