#include <bits/stdc++.h>
using namespace std;

int main(void){
    int d,n,i;
    cin >> d >> n;

    if(d == 0){
        if(n <= 99){
            cout << n << endl;
        }
        if(n == 100){
            cout << 101 << endl;
        }
    }

    if(d == 1){
        if(n <= 99){
            cout << n*100 << endl;
        }
        if(n == 100){
            cout << 101*100 << endl;
        }
    }

    if(d == 2){
        if(n <= 99){
            cout << n*10000 << endl;
        }
        if(n == 100){
            cout << 101*10000 << endl;
        }
    }

    return 0;
}