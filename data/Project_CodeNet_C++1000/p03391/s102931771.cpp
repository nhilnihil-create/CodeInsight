#include <bits/stdc++.h>
using namespace std;

long n,x,y,ans,check,num=1e10;

int main(){
    scanf("%ld",&n);
    while(n--){
        scanf("%ld%ld",&x,&y);
        ans += x;
        if(x != y)  check = 1;
        if(x > y && num > y) num = y;
    }
    printf("%ld",check ? ans-num : 0);
}