#include <bits/stdc++.h>
using namespace std;

int A[200005];

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i ++){
        scanf("%d", &A[i]);
    }

    if(A[0] != 0){
        printf("-1");
        return 0;
    }

    for(int i = 1; i < N; i ++){
        if(A[i]-A[i-1] > 1){
            printf("-1");
            return 0;
        }
    }

    long long ans = 0;
    for(int i = 1; i < N; i ++){
        if(A[i] == A[i-1]+1){
            ans ++;
        }else{
            ans += A[i];
        }
    }

    printf("%lld\n", ans);
    return 0;
}
