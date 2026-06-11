#include<stdio.h>

int main(){
    int A, B;
    int start = 1;
    
    scanf("%d", &A);
    scanf("%d", &B);
    
    for(int i=0;i<A;i++) {
    	if ((start*2)<(start+B)) {
    		start*=2;
		} else {
			start+=B;
		}
	}
    printf("%d", start);
    return 0;
}