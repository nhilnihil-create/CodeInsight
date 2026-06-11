#include"stdio.h"

int main(){
    int N;
    int sum = 0;
    int check = 0;

    scanf("%d", &N);

    int L[N];

    for (int i = 0; i < N; i++){
        scanf("%d", &L[i]);
        sum += L[i];
    }

    for (int j = 0; j < N; j++){
        if(L[j] >= sum - L[j]){
            check++;
        }
    }

    if(check == 0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}