#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string s;
    cin >> s;
    long long k;
    cin >> k;

    for(long long i = 0; i < k; i++){
        if(s[i] != '1'){
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("1\n");

    return 0;
}