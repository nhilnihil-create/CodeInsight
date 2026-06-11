#include<stdio.h>

int main(){
	int a,b;
	scanf("%d %d", &a,&b);
	char code[a+b+2]="";
	scanf("%s", code);
	if(code[a]=='-'){
		for(int i=0;i<a+b+1;i++){
			if(i==a+b){
				if((code[i]>=48)&&(code[i]<=57)){
					printf("Yes");
				}
				else{
					printf("No");
					break;
				}
			}
			if(i!=a){
				if((code[i]>=48)&&(code[i]<=57)) continue;
				else{
					printf("No");
					break;
				}
			}
		}
	}
	else printf("No");
	return 0;
}