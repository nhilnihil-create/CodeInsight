#include <bits/stdc++.h>
using namespace std;

long floor_sqrt(long n){
    long s = floor(sqrt(n));
    if(s*s>n){
        s--;
    }
    if((s+1)*(s+1)<=n){
        s++;
    }
    return s;
}

long calc(long a, long b){
    long s = floor_sqrt(a*b-1);
    long ans = 2*s;
    if(min(a, b)<=s){
        ans--;
    }
    if(s*(s+1)>a*b-1){
        ans--;
    }
    return ans;
}

int main(void){
    long a, b, q;
    scanf("%ld", &q);
    for(long i=0; i<q; i++){
        scanf("%ld %ld", &a, &b);
        printf("%ld\n", calc(a, b));
    }
    return 0;
}
