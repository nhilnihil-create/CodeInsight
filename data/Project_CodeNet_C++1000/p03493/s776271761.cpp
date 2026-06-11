#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int a;
    int d=0;
    cin >> a;

    if (a/100==1){d++;}
    if (a>=100){
        if ((a-100)/10==1){d++;}
    }
    else{
        if (a/10==1){d++;}
    }
    if (a%2==1){d++;}
    cout << d << endl;
}