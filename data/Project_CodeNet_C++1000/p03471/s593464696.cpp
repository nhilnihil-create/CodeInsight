#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
    int n, y, i, j;
    cin >> n >> y;
    y /= 1000;
    for(i=n; i>=0; i--){
        for(j=n-i; j>=0; j--){
            if(i*10 + j*5 + n-i-j == y) goto SKIP;
        }
    }
    cout << "-1 -1 -1\n";
    return 0;
SKIP:
    printf("%d %d %d\n", i, j, n-i-j);
    return 0;
}