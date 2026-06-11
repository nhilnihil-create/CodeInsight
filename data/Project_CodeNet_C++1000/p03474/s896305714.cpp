#include <stdio.h>

int main (){

    int i;
    int G, N;
    scanf("%d %d", &G, &N);
    char str [G + N +1];
    scanf("%s", &str);

    int asw = 0;
    for(i = 0; i<G+N+1; i++){
        if (i != G) 
        {if (str[i]>='0' && str[i]<='9'){
            asw++;
        }
    }else if (str[i] == '-'){
        asw++;
    }
    }
    if (asw == G + N + 1){
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}