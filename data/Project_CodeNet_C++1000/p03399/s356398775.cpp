#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void){
    int a = 0, b = 0, c = 0, d = 0; 
    int ans = 0;

    scanf("%d%d%d%d", &a, &b, &c, &d);

    if(a <= b){
        ans = a;
    }else{
        ans = b;
    }

    if(c <= d){
        ans += c;
    }else{
        ans += d;
    }

    printf("%d\n", ans);

    return 0;

} 
