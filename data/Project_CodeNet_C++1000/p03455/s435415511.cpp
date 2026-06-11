#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main(){

    long long a, b;

    cin >> a >> b;

    if((a*b) % 2 ==0){
        printf("Even\n");
    }
    else{
        printf("Odd\n");
    }

    return 0;

}