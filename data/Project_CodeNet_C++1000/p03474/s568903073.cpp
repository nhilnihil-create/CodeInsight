#include <stdio.h>

int main (){
    int a, b, mark = 0, ctr = 0;
    scanf("%d %d", &a, &b);

    char input[a+b+1];
    scanf("%s", input);
    
    for(int i=0; i < a+b+1; i++){
        if(input[i]== '-' && i == a ){
            mark = 1;
        } else if (input[i] >= '0' && input[i] <= '9'){
            ++ctr;
            }
        }

    if(mark == 1 && ctr == a+b){
        printf("Yes\n");
    } else {
        printf("No\n");
    }

	return 0;
}
