#include<cstdio>

int main (){
    int R;
    scanf("%d", &R);
    if(R < 1200){
        printf("ABC");
    } else if (1199 < R  && R < 2800){
        printf("ARC");
    } else {
        printf("AGC");
    }
}