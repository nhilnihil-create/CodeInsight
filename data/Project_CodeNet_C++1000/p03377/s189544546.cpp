#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int a,b, x;

    scanf("%d %d %d", &a, &b, &x);

    if((a+b) >= x &&  b >= (x - a) && x >= a){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}