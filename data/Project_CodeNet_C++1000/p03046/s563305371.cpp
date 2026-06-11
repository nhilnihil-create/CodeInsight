/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

int n;
int k;

int main(){
    scanf("%d%d" , &n , &k);
    int xr = 0;
    for(int i = 1; i < (1 << n); i++){
        if(i == k)
            continue;
        xr ^= i;
    }
    if(k == 0){
        for(int i = 0; i < (1 << n); i++){
            printf("%d %d " , i , i);
        }
        return 0;
    } else if(n >= 2 && xr == k){
        printf("%d " , k);
        for(int i = (1 << n) - 1; i >= 0; i--){
            if(i == k)
                continue;
            printf("%d " , i);
        }
        printf("%d " , k);
        for(int i = 0; i < (1 << n); i++){
            if(i == k)
                continue;
            printf("%d " , i);
        }
        puts("");
        return 0;
    }
    puts("-1");
}