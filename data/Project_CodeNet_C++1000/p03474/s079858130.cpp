#include <stdio.h>
#include <string.h>

int main(){
	int F, L, count=0;
	scanf("%d %d", &F, &L);
	char add [L+F+2];
	scanf("%s", &add);
	
	for (int i=0; i<F+L+1; i++){
		if (i!=F){
			if (add[i]>=48 && add[i]<=57){
				count++;	
			}	
		} else {
			if (add[i]=='-'){
				count++;
			}
		}
	}
	(count==F+L+1)? (printf("Yes\n")):(printf("No\n"));	
return 0;
}