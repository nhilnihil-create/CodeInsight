#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A, B;
    scanf("%d%d%d", &N, &A, &B);

    if((B-A)%2 == 1){
        printf("Borys");
    }else{
        printf("Alice");
    }
    return 0;
}
