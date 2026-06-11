#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    if(k % 2 == 0){
        long long delta = a - b;
        if(abs(delta) > 1e18){
            printf("Unfair\n");
        }
        else{
            cout << delta << endl;
        }

    }
    else{
        long long delta = b - a;
        if(abs(delta) > 1e18){
            printf("Unfair\n");
        }
        else{
            cout << delta << endl;
        }
    }
    return 0;
}