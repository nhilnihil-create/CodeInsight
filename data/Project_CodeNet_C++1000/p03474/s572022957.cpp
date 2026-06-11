#include<stdio.h>

int main(){
    int A, B, count=0;
    scanf("%d %d", &A,&B);
    char add[A+B+2];
    scanf("%s", add);
    
    for(int i=0;i<A+B+1;i++){
        if(i!=A){
            if(add[i]>=48 && add[i]<=57){
                count++;
            } 
        } else {
            if(add[i]=='-'){
                count++;
            }
        }
    }
    
    if (count==A+B+1) {
    	printf("Yes");
    	return 0;
	}else {
		printf("No");
	}
	
    return 0;
}