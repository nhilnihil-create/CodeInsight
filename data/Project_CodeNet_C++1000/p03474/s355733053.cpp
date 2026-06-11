#include <stdio.h>

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	char str[a+b+1];
	scanf("%s", str);
	int flag = 0;
	for (int i=0; str[i] != '\0'; i++){
		if (str[i] >= '0' && str[i] <= '9'){
			continue;
		}
		else{
			flag++;
		}
		if (str[a] != '-'){
			flag = 0;
			break;
		}
		if (flag > 1){
			break;
		}
	}
	
	if (flag == 1){
		printf("Yes\n");
	}	
	else{
		printf("No\n");
	}
    return 0;
}
