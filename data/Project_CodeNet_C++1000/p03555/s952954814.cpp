#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    char c[2][3];

    for(long long i = 0; i < 2; i++){
        for(long long j = 0; j < 3; j++){
            cin >> c[i][j];
             
        }
    }

    char c_re[2][3];

    for(long long i = 0; i < 2; i++){
        for(long long j = 0; j < 3; j++){
            if(i == 0) c_re[i][j] = c[i+1][2-j];
            else c_re[i][j] = c[i-1][2-j];
        }
    }

    for(long long i = 0; i < 2; i++){
        for(long long j = 0; j < 3; j++){
            if(c[i][j] != c_re[i][j]){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}