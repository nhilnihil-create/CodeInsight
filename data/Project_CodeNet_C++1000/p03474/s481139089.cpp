#include <stdio.h>
int main(){
	int a, b, count=0;
	scanf("%d %d", &a, &b);
	char c[a+b+2];
	scanf("%s", c);
	for(int i=0; i<a+b+1; i++){
		if(i!=a){
			if(c[i]>=48 && c[i]<=57){
                count++;
            } 
		}else {
			if (c[i]=='-'){
				count++;
			}
		}
	}
	count==a+b+1? printf("Yes\n"): printf("No\n");
	return 0;
}
