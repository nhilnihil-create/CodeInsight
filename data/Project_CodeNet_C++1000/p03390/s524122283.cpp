#include<bits/stdc++.h>
using namespace std;

long long int N, A, B, C, l, r, m;

int main(){
    scanf("%lld", &N);
    for(int i = 0; i < N; ++i){
        scanf("%lld%lld", &A, &B);
        if(A > B)swap(A, B);
        if(A == B){printf("%lld\n", (A - 1) * 2);continue;}
        l = A;
        r = B;
        C = A * B;
        while(r > l + 1){
            m = (l + r) / 2;
            (m * m > C - 1 ? r : l) = m;
        }
        C = l;
        printf("%lld\n", (C - 1) * 2 + (C * (C + 1) < A * B));
    }
    return 0;
}
