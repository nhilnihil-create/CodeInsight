#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void){
    int a = 0, b = 0;
    int ans = 0;

    scanf("%d%d", &a, &b);

    ans += a - 1;

    if(a <= b){
        ans++;
    }

    printf("%d\n", ans);

    return 0;

} 
