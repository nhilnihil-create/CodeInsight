#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	bool xxx = true;
	char lmao[a+b+10];
	scanf("%s",&lmao);
	for(int i=0;i<a+b+1;i++){
		if(i == a){
			if(lmao[i] != '-'){
				printf("No\n");
				xxx=false;
				break;
			}
		}
		else{
			if(!(lmao[i]>=48 && lmao[i]<=57)){
				printf("No\n");
				xxx=false;
				break;
			}
		}
	}
	if(xxx) printf("Yes\n");
	return 0;
}